#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 401;

bool arr[N][N];
int pre[N][N];
int scr[N];
int n, m;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n >> m;
        FOR_(i, 1, n) {
            FOR_(j, 1, m) {
                char x; cin >> x;
                arr[i][j] = x == '1' ? 1 : 0;
            }
        }

        int ans = INF;

        FOR_(i, 1, n) {
            FOR_(j, 1, m) {
                pre[i][j] = arr[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
            }
        }

        auto get = [](int x1, int y1, int x2, int y2) -> int {
            return pre[x2][y2] - pre[--x1][y2] - pre[x2][--y1] + pre[x1][y1];
        };

        auto calc = [&get](int x1, int y1, int x2, int y2) -> int {
            return get(x1 + 1, 1, x2 - 1, y2 - 1) + (x2 - x1 - 1) - get(x1 + 1, y1, x2 - 1, y2) + (y1 - 1) + (y2 - 1) - get(x1, 1, x1, y1 - 1) - get(x2, 1, x2, y2 - 1);
        };

        FOR_(t, 1, n) {
            FOR_(b, t + 4, n) {
                FOR_(x, 1, m) {
                    scr[x] = calc(t, x, b, x);
                }
                for (int x = m - 1; x >= 1; --x) {
                    scr[x] = min(scr[x], scr[x + 1]);
                }
                FOR_(l, 1, m) {
                    if (l + 3 > m)
                        continue;
                    int x = scr[l + 3];
                    x -= get(t + 1, 1, b - 1, l) - get(t, 1, t, l) - get(b, 1, b, l) + 2 * l;
                    x += (b - t - 1) - get(t + 1, l, b - 1, l);
                    ans = min(ans, x);
                }
            }
        }

        cout << ans << '\n';
    }
    return 0;
}