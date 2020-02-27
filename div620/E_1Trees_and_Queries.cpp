#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define FOR_(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))
constexpr int M = (int)1e5 + 1;

vector<int> edges[M];
int depth[M];
int no2serial[M], serial2no[M];
int locInTrip[M];
constexpr int N = 1 << 20;
int segTree[N];
int n;

inline int power2RoundUp(int x) {
    x--;
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    x++;
    return x;
}

void init(const vector<int>& v) {
    n = power2RoundUp(v.size());
    for (int i = 0; i < n; ++i) {
        segTree[n + i] = (i < v.size() ? v[i] : INF); 
    }
    int l = n;
    int r = 2*n - 1;
    while (l > 1) {
        l /= 2;
        r /= 2;
        for (int i = l; i <= r; ++i) {
            segTree[i] = min(segTree[2*i], segTree[2*i + 1]);
        }
    }
}

int nextSerial = 0;
void dfs(int here, int d, int parent, vector<int>& v) {
    no2serial[here] = nextSerial;
    serial2no[nextSerial] = here;
    nextSerial++;

    depth[here] = d;
    locInTrip[here] = v.size();
    v.push_back(no2serial[here]);
    for (auto child : edges[here]) {
        if (child == parent) continue;
        dfs(child, d + 1, here, v);
        v.push_back(no2serial[here]);
    }
}

int lca(int a, int b) {
    a += n; b += n;
    int s = INF;
    while (a <= b) {
        if (a%2 == 1) s = min(s, segTree[a++]);
        if (b%2 == 0) s = min(s, segTree[b--]);
        a /= 2; b /= 2;
    }
    return s;
}

int distance(int v1, int v2) {
    int lc1 = locInTrip[v1];
    int lc2 = locInTrip[v2];

    if (lc1 > lc2) swap(lc1, lc2);
    return depth[v1] + depth[v2] - 2 * depth[serial2no[lca(lc1, lc2)]];
}

inline bool validDistance(int d, int k) {
    return (d <= k) && ((k - d) % 2 == 0);
}
int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int nodes; cin >> nodes;
    FOR(i, 0, nodes - 1) {
        int v1, v2; cin >> v1 >> v2;
        edges[v1].push_back(v2);
        edges[v2].push_back(v1);
    }

    vector<int> trip;
    dfs(1, 1, 0, trip);
    init(trip);

    int q; cin >> q;
    while (q--) {
        int x, y, a, b, k; cin >> x >> y >> a >> b >> k;
        bool possible = false;
        possible |= validDistance(distance(a, b), k);
        possible |= validDistance(distance(a, x) + 1 + distance(y, b), k);
        possible |= validDistance(distance(a, y) + 1 + distance(x, b), k);
        cout << (possible ? "YES" : "NO") << "\n";
    }

    return 0;
}