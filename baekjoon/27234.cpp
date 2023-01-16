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

constexpr int N = 160;
constexpr int M = 100;

ll n, m, k, q, ans;
ll c[N], dp[N][N];

ll modpow(ll a, ll x) {
    ll ret = 1;
    ll base = a;
    while (x) {
        if (x % 2 == 1)
            ret = (ret * base) % m;
        
        base = (base * base) % m;
        x /= 2;
    }
    return ret;
}

ll getDp(ll n, ll k) { // use n cups, k on the lowest level
    if (n == k) return modpow(2, n);
    if (k <= 0) return 0;
    if (k > n) return 0;

    ll &ref = dp[n][k];

    if (ref != -1) return ref;

    ref = 0;

    ref = 2LL * getDp(n-1, k-1) % m;
    rep_(i, 1, k-1) {
        rep_(x, i, n-k) {
            ll y = n - (i + 1) - x;
            ref = (ref + c[i+1] * getDp(x, i) % m * getDp(y, k - i - 1) % m) % m;
        }
    }

    return ref;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    c[0] = 1;
    c[1] = 2;
    rep(i, 2, N) c[i] = (c[i-1] + c[i-2]) % m;

    memset(dp, -1, sizeof(dp));

    ll ans = 0;
    rep_(k, 1, n) {
        ans = (ans + getDp(n, k)) % m;
    }

    cout << ans << '\n';
    
    return 0;
}