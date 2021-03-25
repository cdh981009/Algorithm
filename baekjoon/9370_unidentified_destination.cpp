#include <bits/stdc++.h>

using namespace std;

#define INF INT32_MAX
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

typedef pair<pair<long long, int>, int> pli;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    while (tc--) {
        int n, m, t; cin >> n >> m >> t;
        // vertex, edge, candidates
        int s, g, h; cin >> s >> g >> h;
        // start, edges
        vector<vector<pair<int, int>>> edges(n + 1, vector<pair<int, int>>());
        map<int, bool> candidates;
        FOR(i, 0, m) {
            int v, u, w;
            cin >> v >> u >> w;
            edges[v].push_back({u, w});
            edges[u].push_back({v, w});
        }
        FOR(i, 0, t) {
            int c; cin >> c;
            candidates[c] = false;
        }

        priority_queue<pli, vector<pli>, greater<pli>> q; // pair<<distance, !g-h>, vertex>
        vector<long long> dist(n + 1, INF);
        vector<bool> visited(n + 1, false);
        q.push({{0, 1}, s});

        while (!q.empty()) {
            auto top = q.top();
            q.pop();
            auto d = top.first.first;
            auto gh = top.first.second;
            auto node = top.second;
            if (visited[node])
                continue;
            // cout << node << endl;
            dist[node] = d;
            visited[node] = true;
            if (!gh && candidates.count(node) != 0) {
                candidates[node] = true;
            }
            for (auto next : edges[node]) {
                auto dst = next.first;
                if (visited[dst])
                    continue;
                auto weight = next.second;
                auto ngh = gh;
                if ((node == g && dst == h) || (node == h && dst == g))
                    ngh = 0;
                q.push({{d + weight, ngh}, dst});
            }
        }
        for (auto c : candidates) {
            if (c.second)
                cout << c.first << " ";
        }
        cout << "\n";
    }
    return 0;
}