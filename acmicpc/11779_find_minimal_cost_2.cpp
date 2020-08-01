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

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> edges(n + 1, vector<pair<int, int>>());
    vector<long long> dist(n + 1, INF);

    FOR(i, 0, m) {
        int v, u, w;
        cin >> v >> u >> w;
        edges[v].push_back({u, w});
    }

    int s, e; cin >> s >> e;

    typedef pair<long long, pair<int, int>> plpii;
    priority_queue<plpii, vector<plpii>, greater<plpii>> q; // pair<distance, vertex, prev>

    vector<bool> visited(n + 1, false);
    vector<int> backtrack(n + 1);
    q.push({0, {s, -1}});

    while (!q.empty()) {
        auto top = q.top(); q.pop();
        auto d = top.first;
        auto node = top.second.first;
        auto prev = top.second.second;
        //cout << "node" << node << " dist " << d << endl;
        if (visited[node])
            continue;
        dist[node] = d;
        visited[node] = true;
        backtrack[node] = prev;
        if (node == e)
            break;
        for (auto next : edges[node]) {
            auto dst = next.first;
            if (visited[dst])
                continue;
            auto weight = next.second;
            q.push({d + weight, {dst, node}});
        }
    }

    cout << dist[e] << "\n";

    vector<int> path;
    int curr = e;
    while (true) {
        path.push_back(curr);
        if (curr == s)
            break;
        curr = backtrack[curr];
    }

    cout << path.size() << "\n";
    for (int i = path.size() - 1; i >= 0; --i)
        cout << path[i] << " ";
    cout << "\n";

    return 0;
}