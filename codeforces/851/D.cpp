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

constexpr int N = 3010;
constexpr int M = 1000000000 + 7;

ll n, m, k, q, ans;
ll a[N];

ll modpow(int a, int x) {
    ll base = a;
    ll ret = 1;
    while (x) {
        if (x % 2) {
            ret = ret * base % M;
        }
        base = base * base % M;
        x /= 2;
    }
    return ret;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    rep(i, 0, n) { cin >> a[i]; }

    rep(i, 0, n) {
        rep(j, i + 1, n) {
            ll dist = a[j] - a[i];
            auto it1 = lower_bound(a, a + n, a[i] - dist) - a;
            auto it2 = n - (lower_bound(a, a + n, a[j] + dist) - a);
            // cout << it1 << ' ' << it2 << '\n';
            ans += modpow(2, it1 + it2);
            ans %= M;
        }
    }

    cout << ans << '\n';

    return 0;
}