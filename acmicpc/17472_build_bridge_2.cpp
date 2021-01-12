// 17472: 다리 만들기 2
// https://www.acmicpc.net/problem/17472
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 10;
constexpr int I = 6;

int n, m;
int iCnt = 0;

int map[N][N];
bool visited[N][N];

int adj[I][I];
vector<pair<int, pair<int, int>>> edges;

int root[I];

int find(int x) {
	return root[x] == x ? x : (root[x] = find(x));
}

bool same(int x, int y) {
	return find(x) == find(y);
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	root[y] = x;
}

int kruscal() {
	FOR(i, 0, iCnt) {
		FOR(j, i + 1, iCnt) {
			if (adj[i][j]) {
				edges.push_back({adj[i][j], {i, j}});
			}
		}
	}
	
	FOR(i, 0, iCnt) {
		root[i] = i;
	}
	
	sort(edges.begin(), edges.end());
	
	int ans = 0;
	int connect = 0;
	FOR(i, 0, edges.size()) {
		auto p = edges[i];
		int x = p.second.first;
		int y = p.second.second;
		
		if (!same(x, y)) {
			connect++;
			unite(x, y);
		}
	}
	
	return (connect != iCnt) ? 0 : ans;
}

vector<pair<int, int>> islandCells[I];

void dfs(int x, int y) {
	map[x][y] = iCnt;
	
	auto inBound = [](int x, int y) {
		return (x >= 0 || y >= 0 || x < n || y < m);
	}
	
	const static int move[2] = {-1, +1};
	FOR(i, 0, 2) {
		FOR(j, 0, 2) {
			int nx = x + move[i];
			int ny = y + move[j];
			if (!inBound(nx, ny))
				continue;
			
			if (!visited[nx][ny] && map[nx][ny])
				bfs(nx, ny);
			
			if (!map[nx][ny]) // adjacent cell is empty
				islandCells[iCnt - 1].push_back({x, y});
		}
	}
}

void floodFill() {
	FOR(i, 0, n) {
		FOR(j, 0, m) {
			if (!visited[i][j] && map[i][j]) {
				dfs(i, j);
				iCnt++;
			}
		}
	}
}

// TODO
void getAdj() {
	
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	cin >> n >> m;
	FOR(i, 0, n) {
		FOR(j, 0, m) {
			int x; cin >> x;
			map[i][j] = x;
		}
	}
	
	floodFill();
	
	getAdj();
	
	cout << kruscal() << '\n';

    return 0;
}