#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 201010;
constexpr int M = 1e9 + 7;

int n, k;
ll ans;

ll modpow(ll a, ll x) {
    ll ret = 1;
    ll base = a;
    while (x) {
        if (x % 2) {
            ret = (ret * base) % M;
        }
        base = (base * base) % M;
        x /= 2;
    }
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n >> k;

        ll tmp = modpow(2, n - 1);
        if (n % 2) {
            // odd
            ans = modpow(tmp + 1, k) % M;
        } else {
            // even
            ans = modpow(tmp - 1, k);
            FOR_(x, 0, k - 1) {
                ll a = modpow(tmp - 1, x);
                a *= modpow(modpow(2, k - x - 1), n);
                a %= M;
                ans += a;
                ans %= M;
            }

        }

        cout << ans << '\n';
    }
    return 0;
}