#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 7)
#define fi first
#define se second
#define rep(i, a, b) for (ll i = (a); i < (b); ++i)
#define rep_(i, a, b) for (ll i = (a); i <= (b); ++i)
#define repr_(i, a, b) for (ll i = (a); i >= (b); --i)
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (ll i = (a); i <= (b); ++i)
#define printYN(pos) cout << (pos ? "YES" : "NO") << '\n'
#define printPOS(pos) cout << (pos ? "POSSIBLE" : "IMPOSSIBLE") << '\n'

using ll = long long;
using pii = pair<ll, ll>;
using pll = pair<ll, ll>;
using vi = vector<ll>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using mii = map<ll, ll>;
using mll = map<ll, ll>;

constexpr ll N = 20;

ll n;
ll ans;
ll a[N][N], ax[N][N];

void doMove(int dir) {
    memset(ax, 0, sizeof(ax));
    if (dir == 0) {
        rep(i, 0, n) {
            int k = 0;
            ax[i][0] = a[i][0];
            rep(j, 1, n) {
                if (a[i][j] == 0) continue;
                if (a[i][j] == ax[i][k]) {
                    ax[i][k] *= 2;
                    k++;
                } else {
                    if (ax[i][k] != 0)
                        k++;
                    ax[i][k] = a[i][j];
                }
            }
        }
    } else if (dir == 1) {
        rep(i, 0, n) {
            int k = n - 1;
            ax[i][n - 1] = a[i][n - 1];
            repr_(j, n - 2, 0) {
                if (a[i][j] == 0) continue;
                if (a[i][j] == ax[i][k]) {
                    ax[i][k] *= 2;
                    k--;
                } else {
                    if (ax[i][k] != 0)
                        k--;
                    ax[i][k] = a[i][j];
                }
            }
        }
    } else if (dir == 2) {
        rep(i, 0, n) {
            int k = 0;
            ax[0][i] = a[0][i];
            rep(j, 1, n) {
                if (a[j][i] == 0) continue;
                if (a[j][i] == ax[k][i]) {
                    ax[k][i] *= 2;
                    k++;
                } else {
                    if (ax[k][i] != 0)
                        k++;
                    ax[k][i] = a[j][i];
                }
            }
        }
    } else {
        rep(i, 0, n) {
            int k = n - 1;
            ax[n - 1][i] = a[n - 1][i];
            repr_(j, n - 2, 0) {
                if (a[j][i] == 0) continue;
                if (a[j][i] == ax[k][i]) {
                    ax[k][i] *= 2;
                    k--;
                } else {
                    if (ax[k][i] != 0)
                        k--;
                    ax[k][i] = a[j][i];
                }
            }
        }
    }
    swap(a, ax);
}

void solve(int x) {
    if (x == 5) return;

    ll temp[N][N];
    memcpy(temp, a, sizeof(a));

    rep(i, 0, 4) {
        doMove(i);
        rep(j, 0, n) rep(k, 0, n)
            ans = max(ans, a[j][k]);
        solve(x + 1);
        memcpy(a, temp, sizeof(a));
    }
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    rep(i, 0, n) rep(j, 0, n) cin >> a[i][j];
    solve(0);

    cout << ans << '\n';

    return 0;
}