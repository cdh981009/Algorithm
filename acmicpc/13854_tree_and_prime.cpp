// 13854: 트리와 소수
// https://www.acmicpc.net/problem/13854
#include <bits/stdc++.h>

using namespace std;

#define INF INT32_MAX
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

// sieve
constexpr int P = 5e4;
bool isPrime[P + 1];
vector<int> primes;

void sieve() {
    FOR_(i, 0, P) {
        isPrime[i] = true;
    }
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= P; ++i)
        if (isPrime[i])
            for (int j = i * i; j <= P; j += i)
                isPrime[j] = false;

    FOR_(i, 0, P)
    if (isPrime[i])
        primes.push_back(i);
}

// fast fourier transform

constexpr double PI = 3.14159265358979323846;
using C = complex<double>;

vector<int> indexTable;

void FFT(vector<C>& v, bool invert = false) {
    int n = v.size();
    int newN = 1;

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

    // 재배열
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

// centroid decomposition
constexpr int V = 5e4 + 1;
constexpr int LOGV = 15;

int n;

vector<int> adj[V];
int ancestor[LOGV][V]; // 2^x th ancestor
int depth[V];
int sz[V];
bool visited[V];

vector<int> centChildren[V];
int centSz[V];

void dfs(int node) {
    FOR(i, 0, adj[node].size()) {
        int c = adj[node][i];
        if (c == ancestor[0][node])
            continue;

        ancestor[0][c] = node;
        depth[c] = depth[node] + 1;
        dfs(c);
    }
}

void getSize(int node, int prev) {
    int& s = sz[node];
    s = 1;
    FOR(i, 0, adj[node].size()) {
        int c = adj[node][i];
        if (visited[c] || c == prev)
            continue;
        getSize(c, node);
        s += sz[c];
    }
}

// O(log^2 n)
// node 를 루트로 하는 서브트리에서 centroid를 구한다
int getCentroid(int node, int prev, int cap) {
    FOR(i, 0, adj[node].size()) {
        int c = adj[node][i];
        if (visited[c] || c == prev)
            continue;

        if (sz[c] * 2 > cap) {
            return getCentroid(c, node, cap);
        }
    }
    // every child's size of subtree is less than or equal to cap / 2
    return node;
}

// O(n log^2 (n))
void centroidDecomposit(int node, int prev) {
    getSize(node, 0);

    int cent = getCentroid(node, 0, sz[node]);

    centChildren[prev].push_back(cent);
    centSz[cent] = 1;

    visited[cent] = true;

    FOR(i, 0, adj[cent].size()) {
        int c = adj[cent][i];
        if (visited[c] || c == prev)
            continue;

        centroidDecomposit(c, cent);
    }

    centSz[prev] += centSz[cent];
}

// O(log(n))
int lca(int u, int v) {
    if (depth[u] != depth[v]) {
        if (depth[u] > depth[v])
            swap(u, v);

        // v is always lower

        for (int step = LOGV - 1; step >= 0; --step) {
            while (depth[ancestor[step][v]] >= depth[u])
                v = ancestor[step][v];
        }
    }

    // now u and v is on the same depth
    if (u != v) {
        for (int step = LOGV - 1; step >= 0; --step) {
            while (ancestor[step][v] != ancestor[step][u]) {
                v = ancestor[step][v];
                u = ancestor[step][u];
            }
        }
        u = ancestor[0][u];
    }

    return u;
}

// O(log(n))
int distance(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

vector<C> subtreeDist;
vector<C> totalDist;

void getDistVec(int root, int node, vector<C>& vec) {
    vec[distance(root, node)] += 1;

    FOR(i, 0, centChildren[node].size()) {
        int c = centChildren[node][i];
        getDistVec(root, c, vec);
    }
}

long long gcd(long long a, long long b) {
    if (a < b)
        swap(a, b);
    // a > b;
    while (b != 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

double getPrimeDistanceCnt() {
    long long ans = 0;
    FOR_(node, 1, n) {
        int totalSz = centSz[node];
        if (totalSz == 1)
            continue;

        totalDist.resize(4 * (totalSz + 1));
        memset(totalDist.data(), 0, sizeof(C) * totalDist.size());
        totalDist[0] = 1;

        FOR(i, 0, centChildren[node].size()) {
            int c = centChildren[node][i];
            int subSz = centSz[c];

            subtreeDist.resize(4 * (subSz + 1));
            memset(subtreeDist.data(), 0, sizeof(C) * subtreeDist.size());

            getDistVec(node, c, subtreeDist);

            FOR(j, 0, subtreeDist.size())
            totalDist[j] += subtreeDist[j];

            FFT(subtreeDist);
            FOR(j, 0, subtreeDist.size())
            subtreeDist[j] *= subtreeDist[j];
            FFT(subtreeDist, true);

            FOR(j, 0, primes.size()) {
                if (primes[j] >= subtreeDist.size())
                    break;
                ans -= (long long)(subtreeDist[primes[j]].real() + 0.5);
            }
        }

        FFT(totalDist);
        FOR(i, 0, totalDist.size())
        totalDist[i] *= totalDist[i];
        FFT(totalDist, true);

        FOR(i, 0, primes.size()) {
            if (primes[i] >= totalDist.size())
                break;
            ans += (long long)(totalDist[primes[i]].real() + 0.5);
        }
    }

    // cout << ans << '\n';

    long long m = (long long)n * (n - 1);
    long long g = gcd(ans, m);
    m /= g;
    ans /= g;
    return (double)ans / m;
}

int main() {
    // freopen("input.txt", "r", stdin);
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

    depth[0] = -1;
    dfs(1);
    FOR(i, 1, LOGV) {
        FOR_(j, 1, n) {
            ancestor[i][j] = ancestor[i - 1][ancestor[i - 1][j]];
        }
    }

    centroidDecomposit(1, 0);

    double ans = getPrimeDistanceCnt();
    cout << fixed << setprecision(9) << ans << '\n';

    return 0;
}