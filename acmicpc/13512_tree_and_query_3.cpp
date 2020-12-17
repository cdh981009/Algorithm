// 13512: 트리와 쿼리 3
// https://www.acmicpc.net/problem/13512
#include <bits/stdc++.h>

using namespace std;

#define INF INT32_MAX
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e5 + 10;

// heavy-light decomposition

// struct Edge {
//     int u, v, w;
// };

int n;
int chainCnt;
int segIndCnt;

// max tree
int segN;
int segTree[(1 << 19)]; // segTree of edges' weight

// root = 1
vector<int> adj[N]; // only destination
// Edge edges[N]; // src, dest, weight
int parent[N];
int depth[N];
int subTree[N]; // size of subtree

int segInd[N];
int segInd2vertex[N];
int vertex2chain[N];
int chainHead[N];

void dfs(int node) {
    int& s = subTree[node];
    s = 1;
    FOR(i, 0, adj[node].size()) {
        int c = adj[node][i];
        if (c == parent[node])
            continue;
        
        parent[c] = node;
        depth[c] = depth[node] + 1;
        dfs(c);

        s += subTree[c];
    }
}

void decomposit(int node) {
    if (chainHead[chainCnt] == 0)
        chainHead[chainCnt] = node;
    vertex2chain[node] = chainCnt;
    segInd[node] = segIndCnt++;

    int (&st)[N] = subTree;
    sort(adj[node].begin(), adj[node].end(), [&st](const int& l, const int& r) {
        return st[l] > st[r];
    });

    bool first = true;
    FOR(i, 0, adj[node].size()) {
        int c = adj[node][i];
        if (c == parent[node])
            continue;
        
        if (first) {
            first = false;
        } else {
            chainCnt++;
        }

        decomposit(c);
    }
}

void initTree() {
    for(segN = 1; segN < n; segN <<= 1);

    for (int i = 1; i <= 2 * segN; ++i) {
        segTree[i] = INF;
    }

    // // leaf init
    // FOR_(i, 1, n - 1) {
    //     auto& e = edges[i];
    //     if (parent[e.u] == e.v)
    //         swap(e.u, e.v);

    //     // v's parent is u
    //     segTree[segInd[e.v] + segN] = e.w;
    // }

    // // non-leaf init
    // for (int i = segN - 1; i >= 1; --i) {
    //     segTree[i] = min(segTree[2 * i], segTree[2 * i + 1]);
    // }
}

void pointUpdate(int ind, int val) {
    ind += segN;
    // toggle
    segTree[ind] = (segTree[ind] == INF) ? val : INF;

    while (ind > 1) {
        ind >>= 1;
        segTree[ind] = min(segTree[2 * ind], segTree[2 * ind + 1]);
    }
}

int rangeQuery(int a, int b) {
    a += segN;
    b += segN;
    int m = INF;
    while (a <= b) {
        if (a % 2 == 1) // odd
            m = min(m, segTree[a++]);
        if (b % 2 == 0) // even
            m = min(m, segTree[b--]);
        a /= 2;
        b /= 2;
    }
    return m;
}

void init() {
    cin >> n;
    FOR_(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    parent[1] = 0;
    depth[1] = 0;
    dfs(1);
    
    decomposit(1);

    FOR_(i, 1, n) {
        segInd2vertex[segInd[i]] = i;
    }

    initTree();
}

void update(int i) {
    pointUpdate(segInd[i], segInd[i]);
}

int query(int v) {
    int ans = INF;

    int u = 1;
    int uChain = vertex2chain[u];
    while (uChain != vertex2chain[v]) {
        // v is lower or same, jump to parent of chainHead
        int ch = chainHead[vertex2chain[v]];
        ans = min(ans, rangeQuery(segInd[ch], segInd[v]));
        v = parent[ch];
    }

    // now they are on the same chain
    // v is lower or the same
    ans = min(ans, rangeQuery(segInd[u], segInd[v]));

    return (ans == INF) ? -1 : segInd2vertex[ans];
}

int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    init();

    int q; cin >> q;
    FOR(i, 0, q) {
        int t; cin >> t;
        if (t == 1) {
            int i;
            cin >> i;
            update(i);
        } else {
            int v;
            cin >> v;
            cout << query(v) << '\n';
        }
    }
    return 0;
}