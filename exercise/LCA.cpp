#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e5;
constexpr int logN = 17;
int par[N][logN];
vector<int> edge[N];
int depth[N];

void dfs(int node) {
    for (auto child : edge[node]) {
        if (par[node][0] == child)
            continue;
        par[child][0] = node;
        depth[child] = depth[node] + 1;
        dfs(child);
    }
}

int lca(int x, int y) {
    if (depth[x] < depth[y])
        swap(x, y);

    for (int i = logN - 1; i >= 0; --i) {
        int xx = par[x][i];
        if (depth[xx] >= depth[y])
            x = xx;
    }

    if (x == y)
        return x;

    for (int i = logN - 1; i >= 0; --i) {
        int xx = par[x][i];
        int yy = par[y][i];
        if (xx != yy) {
            x = xx;
            y = yy;
        }
    }

    return par[x][0];
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    FOR(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(0);
    FOR(i, 1, logN) {
        FOR(j, 0, n) {
            par[j][i] = par[par[j][i - 1]][i - 1];
        }
    }
    int m;
    cin >> m;
    FOR(i, 0, m) {
        int ans;
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        cout << lca(u, v) + 1 << "\n";
    }
    return 0;
}