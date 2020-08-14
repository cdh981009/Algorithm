#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e5;
int sz[N+1];
vector<vector<int>> edges(N+1);
int n, r, q;

void dfs(int root, int parent) {
    sz[root] = 1;
    for (auto child : edges[root]) {
        if (child == parent) continue;
        dfs(child, root);
        sz[root] += sz[child];
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> r >> q;
    FOR(i, 0, n-1) {
        int u, v; cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    dfs(r, 0);

    FOR(i, 0, q) {
        int x; cin >> x;
        cout << sz[x] << "\n";
    }
    return 0;
}