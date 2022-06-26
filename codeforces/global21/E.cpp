#include <bits/stdc++.h>

using namespace std;

#define INF (1e9+7)
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
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pii>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 401010;
constexpr int M = INF;

ll n, m, q, ans;
ll fac[N], ifac[N];

ll comb(ll n, ll r) {
    return fac[n] * ifac[r] % M * ifac[n - r] % M;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    fac[0] = 1;
    FOR(i, 1, N) {
        fac[i] = fac[i-1] * i % M;
    }
    ifac[0] = ifac[1] = 1;
    FOR(i, 2, N) {
        ifac[i] = ((-M / i + M) % M) * ifac[M % i] % M;
    }
    FOR(i, 1, N) {
        ifac[i] = ifac[i-1] * ifac[i] % M;
    }

    cin >> n;
    ans = 0;
    rep_(i, 0, n) {
        ll x; cin >> x;
        if (x > 0) {
            ans = (ans + comb(x + i, i + 1)) % M;
        }
        // cout << ans << '\n';
    }
    cout << ans << '\n';
    

    return 0;
}