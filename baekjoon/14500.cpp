#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 7)
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep_(i, a, b) for (int i = (a); i <= (b); ++i)
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

constexpr int N = 510;
constexpr int M = 10007;

ll n, m;
int a[N][N], b[N][N];

vector<vector<pii>> vec = {
    {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
    {{0, 0}, {0, 1}, {1, 0}, {1, 1}},
    {{0, 0}, {1, 0}, {2, 0}, {2, 1}},
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 1}}};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> a[i][j];
        }
    }

    ll ans = 0;

    auto inBound = [&](int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    };

    rep(k, 0, 8) {
        rep(i, 0, n) {
            rep(j, 0, m) {
                for (auto &v : vec) {
                    ll res = 0;
                    for (auto [x, y]: v) {
                        int nx, ny;
                        nx = x + i;
                        ny = y + j;
                        if (!inBound(nx, ny)) {
                            res = -1;
                            break;
                        }
                        res += a[nx][ny];
                    }
                    ans = max(ans, res);
                }
            }
        }

        if (k != 3) {
            rep(i, 0, n) {
                rep(j, 0, m) {
                    b[n - i - 1][j] = a[i][j];
                }
            }
            swap(a, b);
        }

        rep(i, 0, n) {
            rep(j, 0, m) {
                b[j][i] = a[i][j];
            }
        }
        swap(a, b);
        swap(n, m);
    }

    cout << ans << '\n';

    return 0;
}