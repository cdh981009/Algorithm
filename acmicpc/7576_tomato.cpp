#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1000;
int n, m;
int t[N][N];
bool visited[N][N];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> m >> n;
    deque<pair<pair<int, int>, int>> q; 
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            int x; cin >> x;
            t[i][j] = x;
            if (x == 1) {
                q.push_back({{i, j}, 0});
            }
        }
    }
    memset(visited, false, sizeof(bool)*N*N);
    int cnt = 0;
    const vector<pair<int, int>> delta = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (!q.empty()) {
        auto p = q.front();
        q.pop_front();
        auto x = p.first.first;
        auto y = p.first.second;
        auto days = p.second;
        cnt = days;
        for (auto d : delta) {
            int i = x + d.first;
            int j = y + d.second;
            if (i >= 0 && i < n && j >=0 && j < m && !visited[i][j] && t[i][j] == 0) {
                // cout << i << " " << j << endl;
                visited[i][j] = true;
                q.push_back({{i, j}, days + 1});
            }
        }
    }
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            if (t[i][j] == 0 && !visited[i][j])
                cnt = -1;
        }
    }
    cout << cnt << endl;
    return 0;
}