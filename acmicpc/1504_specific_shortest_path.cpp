#include <bits/stdc++.h>

using namespace std;

#define INF INT32_MAX
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

typedef pair<long long, int> pli;
int n, m;
constexpr int N = 800;
vector<vector<pair<int, int>>> edges(N + 1, vector<pair<int, int>>());
map<int, vector<long long>> distances;

void dijkstra(int start) {
    priority_queue<pli, vector<pli>, greater<pli>> q; // pair<distance, vertex>
    vector<long long> dist(n + 1, INF);
    vector<bool> visited(n + 1, false);
    q.push({0, start});

    while (!q.empty()) {
        auto top = q.top();
        q.pop();
        auto d = top.first;
        auto node = top.second;
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
    distances[start] = std::move(dist);
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    FOR(i, 0, m) {
        int v, u, w;
        cin >> v >> u >> w;
        edges[v].push_back({u, w});
        edges[u].push_back({v, w});
    }
    int a, b; cin >> a >> b;

    dijkstra(1);
    dijkstra(a);
    dijkstra(b);

    long long ans = distances[1][a] + distances[a][b] + distances[b][n];
    ans = min<long long>(ans, distances[1][b] + distances[b][a] + distances[a][n]);

    cout << ((ans >= INF) ? -1 : ans) << "\n";
    return 0;
}