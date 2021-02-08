// 5719: Almost Shortest Path
// https://www.acmicpc.net/problem/5719
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

// chinese remainder theorem

constexpr int INF = 1e8;
constexpr int N = 500;

vector<pair<int, int>> edges[N];
vector<int> path[N];
int dist[N];
bool visited[N];


int n, m, src, dest;

int solve() {
	priority_queue<pair<int, int>> pq;
	
	FOR(i, 0, n) {
		dist[i] = INF;
	}
	
	dist[src] = 0;
	pq.push({src, 0});
	
	while (!pq.empty()) {
		auto t = pq.top();
		pq.pop();
		int curr = t.first;
		int d = -t.second;
		
		if (visited[curr])
			continue;
		visited[curr] = true;
		
		FOR(i, 0, edges[curr].size()) {
			auto& e = edges[curr][i];
			int next = e.first;
			int w = e.second;
			
			if (d + w < dist[next]) {
				path[next].clear();
				dist[next] = d + w;
				pq.push({next, -dist[next]});
			}
			
			if (d + w == dist[next]) {
				path[next].push_back(curr);
			}
		}
	}
	
	return dist[dest];
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
		memset(visited, 0, sizeof(bool) * N);
		FOR(i, 0, n) {
			edges[i].clear();
			path[i].clear();
		}
		
		FOR(i, 0, m) {
			int u, v, p;
			cin >> u >> v >> p;
			edges[u].push_back({v, p});
		}
		
		int ans = solve();
        cout << (ans == INF ? -1 : ans) << '\n';
    }

    return 0;
}