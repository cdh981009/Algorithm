#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 7)
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep_(i, a, b) for (int i = (a); i <= (b); ++i)
#define repr_(i, a, b) for (int i = (a); i >= (b); --i)
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

constexpr int N = 101010;
constexpr int M = 100;

ll n, m, k, q, ans;
ll a[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        vector<vi> a(n, vi(m));
        ll cnt = 0;
        rep(i, 0, n) {
            string str;
            cin >> str;
            rep(j, 0, m) {
                a[i][j] = (str[j] == '1' ? 1 : 0);
                cnt += a[i][j];
            }
        }

        if (cnt == 0)
            ans = 0;
        else {
            ll mnL = 4;
            rep(i, 0, n - 1) {
                rep(j, 0, m - 1) {
                    ll c = 0;
                    rep(k, 0, 2) {
                        rep(l, 0, 2) {
                            c += a[i + k][j + l];
                        }
                    }

                    rep(k, 0, 2) {
                        rep(l, 0, 2) {
                            ll cc = c - a[i + k][j + l];
                            mnL = max(1LL, min(mnL, cc));
                        }
                    }
                }
            }

            ans = cnt - mnL + 1;
        }
        cout << ans << "\n";
    }

    return 0;
}