#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e4;
int n, m;
vector<int> edges[N + 1];
vector<int> backEdges[N + 1];
bool visited[N + 1];

int cnt = 0;
vector<int> stk;
vector<vector<int>> scc;

void dfs1(int node) {
    visited[node] = true;
    for (auto child : edges[node]) {
        if (!visited[child])
            dfs1(child);
    }
    stk.push_back(node);
}

void dfs2(int node) {
    visited[node] = true;
    for (auto child : backEdges[node]) {
        if (!visited[child])
            dfs2(child);
    }
    scc.back().push_back(node);
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    FOR(i, 0, m) {
        int u, v; cin >> u >> v;
        edges[u].push_back(v);
        backEdges[v].push_back(u);
    }

    FOR_(i, 1, n) {
        if (!visited[i]) {
            dfs1(i);
        }
    }

    FOR_(i, 1, n) {
        visited[i] = false;
    }

    FOR(i, 0, stk.size()) {
        auto node = stk[stk.size() - 1 -i];
        if (!visited[node]) {
            scc.push_back(vector<int>());
            dfs2(node);
            sort(scc.back().begin(), scc.back().end());
        }
    }

    sort(scc.begin(), scc.end());
    cout << scc.size() << "\n";
    for (auto vec : scc) {
        for (auto v : vec) {
            cout << v << " ";
        }
        cout << -1 << "\n";
    }
    return 0;
}