// 10251: 운전 면허 시험
// https : //www.acmicpc.net/problem/10251
#include <bits/stdc++.h>

using namespace std;

#define INF 1e6
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e2 + 1;
// dp[x][y][dir][turn]
// x, y 의 점까지 오는데 바로 전 방향이 dir이고 지금까지 turn 번 꺾었을 때
// 사용한 최소 연료
int dp[N][N][2][N + 10];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int m, n, l, g;
        cin >> m >> n >> l >> g;
        vector<vector<pair<int, int>>> grid(m, vector<pair<int, int>>(n, {INF, INF}));

        FOR(i, 0, m) {
            FOR(j, 0, n - 1) {
                int x;
                cin >> x;
                grid[i][j].first = x;
            }
        }
        FOR(i, 0, m - 1) {
            FOR(j, 0, n) {
                int x;
                cin >> x;
                grid[i][j].second = x;
            }
        }

        FOR(i, 0, m) {
            FOR(j, 0, n) {
                FOR_(k, 0, N + 2) {
                    dp[i][j][0][k] = dp[i][j][1][k] = INF;
                }
            }
        }

        dp[0][0][0][0] = dp[0][0][1][0] = 0;

        // spread
        FOR(i, 0, m) {
            FOR(j, 0, n) {
                auto& ref = dp[i][j];
                FOR_(k, 0, N + 1) {
                    // spreader: dp[i][j][][k];
                    // right -> right
                    dp[i][j + 1][0][k] =
                            min(dp[i][j + 1][0][k], dp[i][j][0][k] + grid[i][j].first);
                    // down -> right
                    dp[i][j + 1][0][k + 1] =
                            min(dp[i][j + 1][0][k + 1], dp[i][j][1][k] + grid[i][j].first);
                    // right -> down
                    dp[i + 1][j][1][k + 1] =
                            min(dp[i + 1][j][1][k + 1], dp[i][j][0][k] + grid[i][j].second);
                    // down - > down
                    dp[i + 1][j][1][k] =
                            min(dp[i + 1][j][1][k], dp[i][j][1][k] + grid[i][j].second);
                }
            }
        }

        auto& ref = dp[m - 1][n - 1];
        int minTurn = N + 5;
        FOR(i, 0, 2) {
            FOR_(j, 0, N + 2) {
                if (ref[i][j] <= g)
                    minTurn = min(minTurn, j);
            }
        }

        if (minTurn == N + 5)
            cout << -1 << "\n";
        else
            cout << l * (n + m - 2) + minTurn << "\n";
    }
    return 0;
}