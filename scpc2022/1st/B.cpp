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

constexpr int N = 501010;
constexpr int M = 1e9 + 7;

ll n, m;
vll a;
ll ans;
ll fac[N], ifac[N];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fac[0] = fac[1] = 1;
    rep(i, 2, N) fac[i] = i * fac[i-1] % M;
    ifac[0] = ifac[1] = 1;
    rep(i, 2, N) ifac[i] = (-M / i + M) % M * ifac[M % i] % M;
    rep(i, 2, N) ifac[i] = ifac[i] * ifac[i-1] % M;

    int T; cin >> T;
    rep(tc, 0, T) {
        cout << "Case #" << tc + 1 << '\n';
        ans = 0;

        cin >> n >> m;
        a = vll(n, 0);
        rep(i, 0, n) {
            cin >> a[i];
            if (i > 0) a[i] += a[i-1];           
        }
        ll total = a[n-1];
        if (total == 0) {
            ll cnt = 0;
            rep(i, 0, n) if (a[i] == 0) cnt++;
            // c(cnt - 1, m - 1);
            if (cnt >= m)
                ans = fac[cnt-1] * ifac[m-1] % M * ifac[cnt - m] % M;
        } else if (total % m == 0) {
            ll t = total / m;
            map<ll, ll> mp;
            mp[0] = 1;
            rep(i, 0, n) {
                auto x = a[i];
                ll cnt = 0;
                if (mp.count(x - t)) cnt = mp[x - t];
                mp[x] = (mp[x] + cnt) % M;
                if (i == n - 1) ans = cnt;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}