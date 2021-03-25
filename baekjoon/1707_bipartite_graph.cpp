// 1707: 이분 그래프
// https://www.acmicpc.net/problem/1707
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int V = 2e4;
constexpr int E = 2e5;

bool side[V];
bool visited[V];

vector<int> edges[V];

bool dfs(int node, int par) {
    visited[node] = true;

    FOR(i, 0, edges[node].size()) {
        auto child = edges[node][i];

        if (child == par) continue;
        if (visited[child]) {
            if (side[child] == side[node])
                return false;
        } else {
            side[child] = !side[node];
            if (!dfs(child, node))
                return false;
        }
    }

    return true;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    while (tc--) {
        memset(visited, 0, sizeof(bool) * V);
        int v, e; cin >> v >> e;

        FOR(i, 0, v) {
            edges[i].clear();
        }

        FOR(i, 0, e) {
            int x, y; cin >> x >> y;
            x--;
            y--;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }

        bool isBipartite = true;

        FOR(i, 0, v) {
            if (!visited[i])
                isBipartite &= dfs(i, -1);
        }

        cout << (isBipartite ? "YES" : "NO") << '\n';
    }
    return 0;
}