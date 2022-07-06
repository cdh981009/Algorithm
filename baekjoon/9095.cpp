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

constexpr int N = 301;
constexpr int M = 100;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll fac[200];
    fac[0] = fac[1] = 1;
    rep(i, 2, 200) {
        fac[i] = fac[i-1] * i;
    }

    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        ll cnt = 0;
        rep_(i, 0, 10) {
            rep_(j, 0, 5) {
                rep_(k, 0, 3) {
                    if (i * 1 + j * 2 + k * 3 == n) {
                        cnt += fac[i + j + k] / fac[i] / fac[j] / fac[k];
                    }
                }
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}