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

constexpr int N = 101010;
constexpr int M = 1000000000;

ll n, m, k, q, ans;
ll a[N], b[N];

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
        cin >> n >> k;
        rep(i, 0, n) cin >> a[i];

        // diameter = min( 2 * min(a1...an), max(min(ai, ai+1)) )
        auto op = [](ll x) {
            ll t = (x + 1) / 2;
            memcpy(b, a, sizeof(ll) * n);

            int kk = k;

            rep(i, 0, n) {
                if (b[i] < t) {
                    if (kk <= 0) return false;
                    b[i] = 1e9;
                    kk--;
                }
            }

            if (kk == 0) {
                ll mx = -1;
                rep(i, 0, n-1)
                    mx = max(mx, min(b[i], b[i+1]));
                return mx >= x;
            } else if (kk == 1) {
                ll mx = -1;
                rep(i, 0, n)
                    mx = max(mx, b[i]);
                return mx >= x;
            } else {
                return true;
            }
            return true;
        };

        
        ll mx = 1e9;
        ll x = 1;
        for (ll step = mx; step >= 1; step /= 2) {
            while (x + step <= mx && op(x + step)) x += step;
        }

        ans = x;
        
        cout << ans << '\n';
    }

    return 0;
}