// 13510: 트리와 쿼리 1
// https://www.acmicpc.net/problem/13510
#include <bits/stdc++.h>

using namespace std;

#define INF
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e3 + 10;

// heavy-light decomposition

struct Edge {
    int u, v, w;
};

int n;
int chainCnt;
int segIndCnt;

// max tree
int segN;
int segTree[(1 << 10)]; // segTree of edges' weight

// root = 1
vector<int> adj[N]; // only destination
Edge edges[N]; // src, dest, weight
int parent[N];
int depth[N];
int subTree[N]; // size of subtree

int segInd[N];
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
    for(segN = 1; segN < n - 1; segN <<= 1);
    
    // leaf init
    FOR_(i, 1, n - 1) {
        auto& e = edges[i];
        if (parent[e.u] == e.v)
            swap(e.u, e.v);

        // v's parent is u
        segTree[segInd[e.v] + segN] = e.w;
    }

    // non-leaf init
    for (int i = segN - 1; i >= 1; --i) {
        segTree[i] = max(segTree[2 * i], segTree[2 * i + 1]);
    }
}

void pointUpdate(int ind, int val) {
    ind += segN;
    segTree[ind] = val;
    while (ind > 1) {
        ind >>= 1;
        segTree[ind] = max(segTree[2 * ind], segTree[2 * ind + 1]);
    }
}

int rangeQuery(int a, int b) {
    a += segN;
    b += segN;
    int m = 0;
    while (a <= b) {
        if (a % 2 == 1) // odd
            m = max(m, segTree[a++]);
        if (b % 2 == 0) // even
            m = max(m, segTree[b--]);
        a /= 2;
        b /= 2;
    }
    return m;
}

void init() {
    cin >> n;
    FOR_(i, 1, n - 1) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    parent[1] = 0;
    depth[1] = 0;
    dfs(1);
    
    decomposit(1);

    initTree();
}

void update(int i, int c) {
    auto& e = edges[i];
    // v is always child
    pointUpdate(segInd[e.v], c);
}

int query(int u, int v) {
    // todo: find lca
    int ans = 0;

    while (vertex2chain[u] != vertex2chain[v]) {
        int uDepth = depth[chainHead[vertex2chain[u]]];
        int vDepth = depth[chainHead[vertex2chain[v]]];

        if (uDepth > vDepth)
            swap(u, v);
        
        // v is lower or same, jump to parent of chainHead
        int ch = chainHead[vertex2chain[v]];
        ans = max(ans, rangeQuery(segInd[ch], segInd[v]));
        v = parent[ch];
    }

    // now they are on the same chain
    if (u != v) {
        if (depth[u] > depth[v])
            swap(u, v);
        
        // v is lower
        ans = max(ans, rangeQuery(segInd[u] + 1, segInd[v]));
    }

    return ans;
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
            int i, c;
            cin >> i >> c;
            update(i, c);
        } else {
            int u, v;
            cin >> u >> v;
            cout << query(u, v) << '\n';
        }
    }
    return 0;
}