#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 500;
constexpr int M = 2010;

int n, m, k;
bool adj[N][N];
vector<int> edges[N];
vector<pair<int, int>> candidates;
bool ans[M];

int visited[N];

bool dfs(int curr) {
    visited[curr] = 1;
    FOR(i, 0, edges[curr].size()) {
        int next = edges[curr][i];
        if (visited[next] == 0) {
            if (!dfs(next))
                return false;
        } else if (visited[next] == 1) {
            return false;
        }
    }
    visited[curr] = 2;
    return true;
}

int main(int argc, char** argv) {
    int T, tc;
    
    freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    for (tc = 0; tc < T; tc++) {
        cin >> n >> m >> k;

        memset(edges, 0, sizeof(vector<int>) * n);
        memset(adj, 0, sizeof(bool) * N * N);
        candidates.clear();

        FOR(i, 0, m) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            edges[u].push_back(v);
            adj[u][v] = true;
        }

        FOR(i, 0, k) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            candidates.push_back({u, v});
        }

        FOR(i, 0, k) {
            auto& p = candidates[i];
            int u = p.first;
            int v = p.second;

            if (adj[u][v]) {
                ans[i] = 0;
            } else if (adj[v][u]) {
                ans[i] = 1;
            } else {
                memset(visited, 0, sizeof(int) * n);
                edges[u].push_back(v);
                if (!dfs(u)) {
                    edges[u].pop_back();
                    edges[v].push_back(u);
                    ans[i] = 1;
                    adj[v][u] = true;
                } else {
                    ans[i] = 0;
                    adj[u][v] = true;
                }
            }
        }

        cout << "Case #" << tc + 1 << '\n';
        FOR(i, 0, k) {
            cout << ans[i];
        }
        cout << endl;
    }

    return 0;
}