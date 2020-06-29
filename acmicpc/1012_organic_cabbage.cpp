#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

void dfs(int i, int j, const vector<vector<bool>>& cab, vector<vector<bool>>& visited) {
    visited[i][j] = true;
    const static vector<pair<int, int>> delta = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (auto p : delta) {
        int x = i + p.first;
        int y = j + p.second;
        if (x >=0 && x < cab.size() && y >=0 && y < cab[0].size() && cab[x][y] && !visited[x][y])
            dfs(x, y, cab, visited);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    while (tc--) {
        int n, m, k; cin >> n >> m >> k;
        vector<vector<bool>> cab(n, vector<bool>(m, false));
        vector<vector<bool>> visited(cab);
        FOR(i, 0, k) {
            int x, y; cin >> x >> y;
            cab[x][y] = true;
        }
        int cnt = 0;
        FOR(i, 0, n) {
            FOR(j, 0, m) {
                if (!visited[i][j] && cab[i][j]) {
                    cnt++;
                    dfs(i, j, cab, visited);
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}