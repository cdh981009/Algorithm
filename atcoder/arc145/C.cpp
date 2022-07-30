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

constexpr ll N = 401010;
constexpr ll M = 998244353;

ll n, a, b, ans;
ll fac[N], ifac[N];

ll modpow(ll a, ll x) {
    ll res = 1;
    ll base = a;
    
    while (x) {
        if (x % 2) res = res * base % M;
        base = base * base % M;
        x /= 2;
    }

    return res;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
    rep(i, 2, N)
        fac[i] = fac[i - 1] * i % M;
    rep(i, 2, N)
        ifac[i] = (- M / i + M) % M * ifac[M % i] % M;
    rep(i, 2, N)
        ifac[i] = ifac[i] * ifac[i-1] % M;
    
    cin >> n;

    auto catalan = [](ll x) {
        return fac[2 * x] * ifac[x] % M * ifac[x + 1] % M;
    };

    ans = catalan(n) * fac[n] % M;
    ans = ans * modpow(2, n) % M;

    cout << ans << '\n';

    return 0;
}