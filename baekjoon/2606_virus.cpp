#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int dfs(int root, const vector<vector<int>>& edges, vector<bool>& visited) {
    int cnt = 1;
    visited[root] = true;
    for (auto it = edges[root].begin(); it != edges[root].end(); ++it) {
        auto nbs = *it;
        if (!visited[nbs])
            cnt += dfs(nbs, edges, visited);
    }
    return cnt;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n + 1, vector<int>());
    FOR(i, 0, m) {
        int src, dst;
        cin >> src >> dst;
        edges[src].push_back(dst);
        edges[dst].push_back(src);
    }
    for (auto &vec : edges)
        sort(vec.begin(), vec.end());
    vector<bool> visited(n + 1, false);
    cout << dfs(1, edges, visited) - 1 << "\n";
    return 0;
}