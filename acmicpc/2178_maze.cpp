#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int n, m;
int maze[100][100];

int bfs() {
    deque<pair<pair<int, int>, int>> deq;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    const static vector<pair<int, int>> delta = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    deq.push_front({{0, 0}, 1});
    visited[0][0] = true;
    int dist = 0;
    while (!deq.empty()) {
        auto p = deq.back();
        auto i = p.first.first;
        auto j = p.first.second;
        auto dist = p.second;
        deq.pop_back();
        if (i == n-1 && j == m-1)
            return dist;
        for (auto next : delta) {
            int x = i + next.first;
            int y = j + next.second;
            if (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && maze[x][y]) {
                visited[x][y] = true;
                deq.push_front({{x, y}, dist + 1});
            }
        }
    }
    return -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            char x; cin >> x;
            maze[i][j] = x - '0';
        }
    }
    cout << bfs() << "\n";
    return 0;
}