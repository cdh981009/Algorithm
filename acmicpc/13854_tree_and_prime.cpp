// 13854: 트리와 소수
// https://www.acmicpc.net/problem/13854
#include <bits/stdc++.h>

using namespace std;

#define INF INT32_MAX
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

// sieve ////////////////////////////////////////////////////////////////
constexpr int P = 5e4;
bool isPrime[P + 1];
vector<int> primes;

void sieve() {
    FOR_(i, 0, P)
        isPrime[i] = true;
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= P; ++i)
        if (isPrime[i])
            for (int j = i * i; j <= P; j += i)
                isPrime[j] = false;
    FOR_(i, 0, P)
        if (isPrime[i])
            primes.push_back(i);
}

// fast fourier transform ////////////////////////////////////////////////
constexpr double PI = 3.14159265358979323846;
using C = complex<double>;

vector<int> indexTable;

void FFT(vector<C>& v, bool invert = false) {
    int n = v.size();
    int newN = 1;

    // v.size() needs to be power of two
    while (newN < n)
        newN <<= 1;
    v.resize(newN);

    indexTable.resize(newN);
    memset(indexTable.data(), 0, sizeof(int) * newN);

    // construct index table
    for (int bit = (newN >> 1), j = 1; bit; bit >>= 1, j <<= 1) {
        for (int i = 0; i < newN; ++i) {
            if ((i / j) & 1) {
                indexTable[i] |= bit;
            }
        }
    }

    // scramble
    FOR(i, 0, newN) {
        if (i < indexTable[i])
            swap(v[i], v[indexTable[i]]);
    }

    int inv = invert ? -1 : 1;
    for (int m = 2; m <= newN; m <<= 1) {
        C e(cos(-2.0 * PI / m * inv), -sin(2.0 * PI / m * inv));
        for (int i = 0; i < newN; i += m) {
            C w = C(1, 0);
            for (int k = 0; k < m / 2; ++k) {
                C even = v[i + k];
                C odd = v[i + k + m / 2] * w;

                v[i + k] = even + odd;
                v[i + k + m / 2] = even - odd;
                w *= e;
            }
        }
    }

    if (invert)
        for (int i = 0; i < newN; ++i)
            v[i] /= newN;
}

// centroid decomposition ////////////////////////////////////////////////////
constexpr int V = 5e4 + 1;

int n;

vector<int> adj[V];
int sz[V];
bool used[V];

void getSize(int node, int prev) {
    int& s = sz[node];
    s = 1;
    FOR(i, 0, adj[node].size()) {
        int c = adj[node][i];
        if (used[c] || c == prev)
            continue;
        getSize(c, node);
        s += sz[c];
    }
}

// O(n * log^2 n)
int getCentroid(int node, int prev, int cap) {
    FOR(i, 0, adj[node].size()) {
        int c = adj[node][i];
        if (used[c] || c == prev)
            continue;

        if (sz[c] * 2 > cap) {
            return getCentroid(c, node, cap);
        }
    }
    // every child's size of subtree is less than or equal to cap / 2
    return node;
}

long long cnt = 0;
vector<C> subtreeDist;
vector<C> totalDist;

void getDistVec(int node, int prev, int dist, vector<C>& vec) {
    FOR(i, 0, adj[node].size()) {
        int c = adj[node][i];
        if (used[c] || c == prev)
            continue;
        getDistVec(c, node, dist + 1, vec);
    }

    if (vec.size() <= dist)
        vec.resize(dist + 1);
    vec[dist] += 1;
}

// O(n log^2 (n))
// centroid decomposition + fast fourier transform
void solve(int node, int prev) {
    getSize(node, 0);

    int cent = getCentroid(node, 0, sz[node]);
    used[cent] = true;

    totalDist.resize(1);
    totalDist[0] = 1;

    // conquer
    FOR(i, 0, adj[cent].size()) {
        int c = adj[cent][i];
        if (used[c] || c == prev)
            continue;

        subtreeDist.clear();
        getDistVec(c, prev, 1, subtreeDist);

        subtreeDist.resize(4 * subtreeDist.size());

        if (subtreeDist.size() > totalDist.size())
            totalDist.resize(subtreeDist.size());

        FOR(i, 0, subtreeDist.size())
            totalDist[i] += subtreeDist[i];

        FFT(subtreeDist);
        FOR(j, 0, subtreeDist.size())
            subtreeDist[j] *= subtreeDist[j];
        FFT(subtreeDist, true);

        FOR(j, 0, primes.size()) {
            if (primes[j] >= subtreeDist.size())
                break;
            cnt -= (long long)(subtreeDist[primes[j]].real() + 0.5);
        }
    }

    FFT(totalDist);
    FOR(i, 0, totalDist.size())
        totalDist[i] *= totalDist[i];
    FFT(totalDist, true);

    FOR(i, 0, primes.size()) {
        if (primes[i] >= totalDist.size())
            break;
        cnt += (long long)(totalDist[primes[i]].real() + 0.5);
    }

    // divide
    FOR(i, 0, adj[cent].size()) {
        int c = adj[cent][i];
        if (used[c] || c == prev)
            continue;

        solve(c, cent);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    sieve();

    cin >> n;
    FOR(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    solve(1, 0);

    long long m = (long long)n * (n - 1);
    double ans = (double)cnt / m;
    cout << fixed << setprecision(9) << ans << '\n';

    return 0;
}