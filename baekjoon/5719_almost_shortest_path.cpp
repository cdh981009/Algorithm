// 5719: Almost Shortest Path
// https://www.acmicpc.net/problem/5719
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int INF = 1e8;
constexpr int N = 500;

int adj[N][N];
bool route[N][N];
int dist[N];
bool visited[N];

int n, m, src, dest;

int solve(int state = 0) {
    memset(visited, 0, sizeof(bool) * N);
    priority_queue<pair<int, int>> pq;

    FOR(i, 0, n) {
        dist[i] = INF;
    }

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        int d = -t.first;
        int curr = t.second;

        if (visited[curr])
            continue;
        visited[curr] = true;

        FOR(next, 0, n) {
			if (visited[next] || !route[curr][next])
				continue;
			
            int w = adj[curr][next];

            if (d + w < dist[next]) {
                dist[next] = d + w;
                pq.push({-dist[next], next});
            }
        }
    }

    if (state == 0) {
        memset(visited, 0, sizeof(bool) * N);

        vector<int> stk;
        stk.push_back(dest);
		visited[dest] = true;

        while (!stk.empty()) {
            int curr = stk.back();
            stk.pop_back();
            FOR(prv, 0, n) {
                if (!route[prv][curr])
                    continue;
				if (dist[prv] + adj[prv][curr] == dist[curr]) {
					route[prv][curr] = false;
					if (!visited[prv]) {
						stk.push_back(prv);
						visited[prv] = true;
					}
				}
            }
        }
        return solve(1);
    } else {
        return dist[dest];
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        cin >> src >> dest;

        memset(adj, 0, sizeof(int) * N * N);
		memset(route, 0, sizeof(bool) * N * N);

        FOR(i, 0, m) {
            int u, v, p;
            cin >> u >> v >> p;
			route[u][v] = true;
			adj[u][v] = p;
        }

        int ans = solve();
        cout << (ans == INF ? -1 : ans) << '\n';
    }

    return 0;
}