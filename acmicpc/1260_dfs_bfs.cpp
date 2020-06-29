#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

void dfs(int root, const vector<vector<int>>& edges, vector<bool>& visited) {
    cout << root << " ";
    visited[root] = true;
    for (auto it = edges[root].begin(); it != edges[root].end(); ++it) {
        auto nbs = *it;
        if (!visited[nbs])
            dfs(nbs, edges, visited);
    }
}

void bfs(int root, const vector<vector<int>>& edges) {
    deque<int> deq;
    vector<bool> visited(edges.size(), false);
    deq.push_front(root);
    visited[root] = true;
    while (!deq.empty()) {
        int curr = deq.back();
        cout << curr << " ";
        deq.pop_back();
        for (auto nbs : edges[curr])
            if (!visited[nbs]) {
                visited[nbs] = true;
                deq.push_front(nbs);
            }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, v;
    cin >> n >> m >> v;
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
    dfs(v, edges, visited);
    cout << "\n";
    bfs(v, edges);
    cout << "\n";
    return 0;
}