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

constexpr int N = 3010101;

ll n, M, k, q, ans;
ll fac[N];
ll invFac[N];
ll g[5];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> M;

    fac[0] = 1;
    fac[1] = 1;
    invFac[0] = 1;
    invFac[1] = 1;
    rep(i, 2, N) {
        fac[i] = fac[i - 1] * i % M;
        invFac[i] = (M - M / i) % M * invFac[M % i] % M;
    }
    rep(i, 2, N) {
        invFac[i] = invFac[i - 1] * invFac[i] % M;
    }

    g[0] = 1;
    g[1] = (fac[2*n] - 1LL + M) % M * 2LL % M;
    g[1] = (g[1] - (fac[n] - 1LL + M) % M + M) % M;
    g[2] = 2LL * fac[2 * n] % M * fac[2 * n] % M * invFac[n] % M;
    g[2] = g[2] - (g[0] + g[1]) % M;
    g[2] = (g[2] + M) % M;

    auto comb = [](ll n, ll r) {
        return fac[n] * invFac[n - r] % M * invFac[r] % M;
    };

    ll x = 0;
    rep_(i, 0, n) {
        x = x + (comb(n, i) * comb(n, n - i) % M * fac[n] % M 
                * comb(i + n, n) % M 
                * fac[n] % M 
                * fac[n] % M);
        x %= M;
    }

    g[2] = (g[2] - x + M) % M;

    g[3] = fac[3LL * n] - ((g[0] + g[1]) % M + g[2]) % M;
    g[3] = (g[3] + M) % M;

    ans = (0LL * g[0] + g[1] + 2LL * g[2] % M) % M;
    ans = (ans + 3LL * g[3] % M) % M;

    cout << ans << '\n';

    return 0;
}