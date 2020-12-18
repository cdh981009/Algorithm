// 13514: 트리와 쿼리 5
// https://www.acmicpc.net/problem/13514
#include <bits/stdc++.h>

using namespace std;

#define INF INT32_MAX
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e5 + 10;
constexpr int LOGN = 17;
// centroid decomposition

int n;

vector<int> adj[N];
int ancestor[LOGN][N]; // 2^x th ancestor
int depth[N];
int sz[N];
bool visited[N];

int centParent[N];
bool isWhite[N];
multiset<int> subtreeWhite[N];

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
        if (visited[c] || c == prev) continue;
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
    centParent[cent] = prev;
    visited[cent] = true;

    FOR(i, 0, adj[cent].size()) {
        int c = adj[cent][i];
        if (visited[c] || c == prev)
            continue;

        centroidDecomposit(c, cent);
    }
}

// O(log(n))
int lca(int u, int v) {
    if (depth[u] != depth[v]) {
        if (depth[u] > depth[v])
            swap(u, v);

        // v is always lower

        for (int step = LOGN - 1; step >=0; --step) {
            while (depth[ancestor[step][v]] >= depth[u])
                v = ancestor[step][v];
        }
    }

    // now u and v is on the same depth
    if (u != v) {
        for (int step = LOGN - 1; step >= 0; --step) {
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

// O(log^2 (n))
void update(int i) {
    // toggle
    isWhite[i] = !isWhite[i]; 
    bool white = isWhite[i];

    int curr = i;
    while (curr != 0) {
        if (white) {
            subtreeWhite[curr].insert(distance(i, curr));
        } else {
            subtreeWhite[curr].erase(subtreeWhite[curr].find(distance(i, curr)));
        }

        curr = centParent[curr];
    }
}

// log(n)
int query(int v) {
    int ans = INF;
    int curr = v;

    while (curr != 0) {
        if (!subtreeWhite[curr].empty())
            ans = min(ans, distance(curr, v) + *subtreeWhite[curr].begin());
        curr = centParent[curr];
    }

    return ans == INF ? -1 : ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 0, n - 1) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    depth[0] = -1;
    dfs(1);
    FOR(i, 1, LOGN) {
        FOR_(j, 1, n) {
            ancestor[i][j] = ancestor[i - 1][ancestor[i - 1][j]];
        }
    }

    centroidDecomposit(1, 0);

    int q; cin >> q;
    FOR(i, 0, q) {
        int t; cin >> t;
        if (t == 1) {
            int i; cin >> i;
            update(i);
        } else {
            int v; cin >> v;
            cout << query(v) << '\n';
        }
    }

    return 0;
}