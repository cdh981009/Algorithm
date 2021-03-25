// 4803: Trees
// https://www.acmicpc.net/problem/4803
#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 1)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 500;

int n, m;
int treeCnt;
bool visited[N];
vector<vector<int>> edges;

bool dfs(int node, int par) {
    visited[node] = true;
    
    FOR(i, 0, edges[node].size()) {
        int child = edges[node][i];

        if (child == par) continue;

        if (visited[child])
            return false;
        if (!dfs(child, node))
            return false;
    }

    return true;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int c = 0;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        
        treeCnt = 0;
        edges = vector<vector<int>>(n, vector<int>());
        memset(visited, 0, sizeof(bool) * N);

        FOR(i, 0, m) {
            int u, v; cin >> u >> v;
            u--;
            v--;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        FOR(i, 0, n) {
            if (!visited[i])
                treeCnt += dfs(i, -1);
        }

        cout << "Case " << ++c << ": ";
        if (treeCnt == 0) {
            cout << "No trees.\n";
        } else if (treeCnt == 1) {
            cout << "There is one tree.\n";
        } else {
            cout << "A forest of " << treeCnt << " trees.\n";
        }
    }

    return 0;
}