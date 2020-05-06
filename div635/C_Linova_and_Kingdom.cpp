#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

const int N = 2e5;
int depth[N+1];
int sub[N+1];
vector<vector<int>> edges(N+1, vector<int>());

void dfs(int node, int parent) {
    int& d = depth[node];
    int& s = sub[node];
    d = depth[parent] + 1;
    s = 1;
    for (auto child : edges[node]) {
        if (child == parent) continue;
        dfs(child, node);
        s += sub[child];
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;
    for (int i = 0; i < n-1; ++i) {
        int u, v; cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    dfs(1, 0);
    vector<pair<int, int>> nodes;
    for (int i = 1; i <= n; ++i)
        nodes.push_back({depth[i] - sub[i], i});

    sort(nodes.rbegin(), nodes.rend());

    long long ans = 0;
    for (int i = 0; i < k; ++i) {
        ans += nodes[i].first;
    }

    cout << ans << endl;
    return 0;
}