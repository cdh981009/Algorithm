#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

struct point {
    int x, y, dist;
    bool wall;
};

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, {false, false}));
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            char x; cin >> x;
            v[i][j] = x - '0';
        }
    }
    queue<point> q;
    q.push({0, 0, 1, 0});
    visited[0][0][0] = true;
    int ans = -1;
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        int cx = p.x, cy = p.y, cd = p.dist;
        bool w = p.wall;
        int nd = cd + 1;
        if (cx == n - 1 && cy == m - 1) {
            ans = cd;
            break;
        }
        const vector<pair<int, int>> list = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto l : list) {
            int nx = cx + l.first;
            int ny = cy + l.second;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (v[nx][ny] == 0 && !visited[nx][ny][w]) {
                    visited[nx][ny][w] = true;
                    q.push({nx, ny, nd, w});
                }
                if (!w && v[nx][ny] == 1 && !visited[nx][ny][true]) {
                    visited[nx][ny][true] = true;
                    q.push({nx, ny, nd, true});
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}