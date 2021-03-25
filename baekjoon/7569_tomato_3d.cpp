#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 100;
int n, m, h;
int t[N][N][N];
bool visited[N][N][N];

struct coord {
    int x, y, z;
};

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> m >> n >> h;
    deque<pair<coord, int>> q; 
    FOR(i, 0, h) {
        FOR(j, 0, n) {
            FOR(k, 0, m) {
                int x; cin >> x;
                t[i][j][k] = x;
                if (x == 1) {
                    q.push_back({{i, j, k}, 0});
                }
            }
        }
    }
    memset(visited, false, sizeof(bool)*N*N*N);
    int cnt = 0;
    const vector<coord> delta = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
    while (!q.empty()) {
        auto p = q.front();
        q.pop_front();
        auto a = p.first.x;
        auto b = p.first.y;
        auto c = p.first.z;
        auto days = p.second;
        cnt = days;
        for (auto d : delta) {
            int i = a + d.x;
            int j = b + d.y;
            int k = c + d.z;
            bool boundary = (
                i >= 0 && 
                i < h && 
                j >= 0 && 
                j < n && 
                k >= 0 &&
                k < m);
             if (boundary && !visited[i][j][k] && t[i][j][k] == 0) {
                // cout << i << " " << j << endl;
                visited[i][j][k] = true;
                q.push_back({{i, j, k}, days + 1});
            }
        }
    }
    FOR(i, 0, h) {
        FOR(j, 0, n) {
            FOR(k, 0, m) {
                if (t[i][j][k] == 0 && !visited[i][j][k])
                    cnt = -1;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}