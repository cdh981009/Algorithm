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

constexpr ll N = 10;

ll n, m;
ll ans;
char a[N][N], ax[N][N];

int doMove(int dir) {
    if (dir == 0) {
        rep(i, 0, n)
            rep(j, 0, m) {
            auto c = a[i][j];
            if (c == 'R' || c == 'B') {
                a[i][j] = '.';
                int k = j;
                while (a[i][k - 1] == '.') {
                    k--;
                }
                if (a[i][k - 1] != 'O')

                    a[i][k] = c;
            }
        }
    } else if (dir == 1) {
        rep(i, 0, n)
            repr_(j, m - 1, 0) {
            auto c = a[i][j];
            if (c == 'R' || c == 'B') {
                a[i][j] = '.';
                int k = j;
                while (a[i][k + 1] == '.') {
                    k++;
                }
                if (a[i][k + 1] != 'O')
                    a[i][k] = c;
            }
        }
    } else if (dir == 2) {
        rep(j, 0, m) {
            rep(i, 0, n) {
                auto c = a[i][j];
                if (c == 'R' || c == 'B') {
                    a[i][j] = '.';
                    int k = i;
                    while (a[k - 1][j] == '.') {
                        k--;
                    }
                    if (a[k - 1][j]  != 'O')
                        a[k][j] = c;
                }
            }
        }
    } else {
        rep(j, 0, m) {
            repr_(i, n - 1, 0) {
                auto c = a[i][j];
                if (c == 'R' || c == 'B') {
                    a[i][j] = '.';
                    int k = i;
                    while (a[k + 1][j] == '.') {
                        k++;
                    }
                    if (a[k + 1][j] != 'O')
                        a[k][j] = c;
                }
            }
        }
    }

    bool r, b;
    r = b = false;
    rep(i, 0, n) rep(j, 0, m)
        if (a[i][j] == 'R') r = true;
        else if (a[i][j] == 'B') b = true;
    if (!b) return 1;
    if (!r) return 2;

    return 0;
}

void solve(ll x) {
    if (x == 10) return;

    char temp[N][N];
    memcpy(temp, a, sizeof(a));

    rep(i, 0, 4) {
        int res = doMove(i);
        if (res == 2) {
            ans = min(ans, x + 1);
            break;
        } else if (res == 0) {
            solve(x + 1);
        }
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

    cin >> n >> m;
    rep(i, 0, n) rep(j, 0, m) cin >> a[i][j];
    ans = INF;

    solve(0);

    if (ans == INF) ans = -1;
    cout << ans << '\n';

    return 0;
}