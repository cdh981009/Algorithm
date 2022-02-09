#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 2e5 + 10;

int h[N];
int n, m;
ll ans;
vector<pii> edge[N];
ll dist[N];
bool visited[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    FOR(i, 0, n) cin >> h[i];
    FOR(i, 0, m) {
        int u, v; cin >> u >> v;
        u--;
        v--;
        edge[u].push_back({v, h[u] > h[v] ? 0 : (h[v] - h[u])});
        edge[v].push_back({u, h[v] > h[u] ? 0 : (h[u] - h[v])});
    }

    // dijkstra
    priority_queue<pii> q;
    FOR(i, 0, n)
        dist[i] = INF;
    dist[0] = 0;
    q.push({0, 0});

    while (!q.empty()) {
        auto p = q.top();
        q.pop();
        int node = p.second;
        ll d = -p.first;
        if (visited[node]) continue;
        visited[node] = true;
        
        for (auto [nxt, w] : edge[node]) {
            if (dist[nxt] > dist[node] + w) {
                dist[nxt] = dist[node] + w;
                q.push({-dist[nxt], nxt});
            }
        }
    }


    // ans
    ans = 0;
    FOR(i, 0, n) {
        ans = max(ans, max(0, h[0] - h[i]) - dist[i]);
    }
    cout << ans << '\n';
    return 0;
}