#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 7)
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep_(i, a, b) for (int i = (a); i <= (b); ++i)
#define repr_(i, a, b) for (int i = (a); i >= (b); --i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)
#define printYN(pos) cout << (pos ? "YES" : "NO") << '\n'
#define printPOS(pos) cout << (pos ? "POSSIBLE" : "IMPOSSIBLE") << '\n'

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 64;
constexpr int M = 7;

int a[N][N];
int mn[N][N][M][M];
int mx[N][N][M][M];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    rep(tc, 0, T) {
        cout << "Case #" << tc + 1 << '\n';

        int n;
        cin >> n;
        ll ans;

        if (n > 64) {
            cout << 0 << '\n';
            continue;
        }

        memset(mn, 0x3f3f3f3f, sizeof(mn));
        memset(mx, 0, sizeof(mx));

        rep(i, 0, n) rep(j, 0, n) {
            cin >> a[i][j];
        }

        rep(i, 0, n) {
            rep(j, 0, n) {
                mn[i][j][0][0] = a[i][j];
                mx[i][j][0][0] = a[i][j];
            }
        }

        rep(k, 1, M) {
            rep(i, 0, n) {
                rep(j, 0, n) {
                    mn[i][j][k][0] = min(mn[i][j][k - 1][0],
                                         mn[min(n - 1, i + (1 << (k - 1)))][j][k - 1][0]);
                    mx[i][j][k][0] = max(mx[i][j][k - 1][0],
                                         mx[min(n - 1, i + (1 << (k - 1)))][j][k - 1][0]);
                }
            }
        }

        rep(l, 1, M) {
            rep(k, 0, M) {
                rep(i, 0, n) {
                    rep(j, 0, n) {
                        mn[i][j][k][l] = min(mn[i][j][k][l - 1],
                                             mn[i][min(n - 1, j + (1 << (l - 1)))][k][l - 1]);
                        mx[i][j][k][l] = max(mx[i][j][k][l - 1],
                                             mx[i][min(n - 1, j + (1 << (l - 1)))][k][l - 1]);
                    }
                }
            }
        }

        auto op = [&](int x1, int y1, int x2, int y2) {
            int i;
            int xd = x2 - x1 + 1, yd = y2 - y1 + 1;
            int xi = 0, yi = 0;

            xi = (31 - __builtin_clz(xd));
            yi = (31 - __builtin_clz(yd));

            int ax1, ax2, res1, res2;

            ax1 = min(mn[x1][y1][xi][yi],
                      mn[x2 - (1 << xi) + 1][y1][xi][yi]);
            ax2 = min(mn[x1][y2 - (1 << yi) + 1][xi][yi],
                      mn[x2 - (1 << xi) + 1][y2 - (1 << yi) + 1][xi][yi]);
            res1 = min(ax1, ax2);

            ax1 = max(mx[x1][y1][xi][yi],
                      mx[x2 - (1 << xi) + 1][y1][xi][yi]);
            ax2 = max(mx[x1][y2 - (1 << yi) + 1][xi][yi],
                      mx[x2 - (1 << xi) + 1][y2 - (1 << yi) + 1][xi][yi]);
            res2 = max(ax1, ax2);

            return (res2 - res1 + 1) == (xd * yd);
        };

        ans = 0;
        rep(i, 0, n)
            rep(j, 0, n)
                rep(k, i, n)
                    rep(l, j, n) if (op(i, j, k, l)) {
            // cout << i << ' ' << j << ' ' << k << ' ' << l << '\n';
            ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}