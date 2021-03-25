#include <bits/stdc++.h>

using namespace std;

#define INF INT64_MAX
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> edges(n + 1, vector<pair<int, int>>());
    vector<long long> dist(n + 1, INF);

    FOR(i, 0, m) {
        int v, u, w;
        cin >> v >> u >> w;
        edges[v].push_back({u, w});
    }

    typedef pair<long long, int> pli;
    priority_queue<pli, vector<pli>, greater<pli>> q; // pair<distance, vertex>

    vector<bool> visited(n + 1, false);
    q.push({0, k});

    while (!q.empty()) {
        auto top = q.top(); q.pop();
        auto d = top.first;
        auto node = top.second;
        //cout << "node " << node << " dist " << d << endl;
        if (visited[node])
            continue;
        dist[node] = d;
        visited[node] = true;
        for (auto next : edges[node]) {
            auto dst = next.first;
            if (visited[dst])
                continue;
            auto weight = next.second;
            q.push({d + weight, dst});
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (dist[i] == INF)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }
    return 0;
}