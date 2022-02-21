#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr ll N = 10101010;
constexpr ll M = 998244353;

ll n, x, y, z;
ll fac[N];
ll ifac[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fac[0] = 1;
    FOR(i, 1, N) {
        fac[i] = i * fac[i - 1];
        fac[i] %= M;
    }

    ifac[0] = 1;
    ifac[1] = 1;
    FOR(i, 2, N) {
        ifac[i] = (((-M / i + M) % M) * ifac[M % i]) % M;
    }

    FOR(i, 2, N) {
        ifac[i] *= ifac[i - 1];
        ifac[i] %= M;
    }

    cin >> n >> x >> y >> z;
    x = abs(x), y = abs(y), z = abs(z);

    if ((n < x + y + z) || (n - (x + y + z)) % 2) {
        cout << 0 << '\n';
    } else {
        ll ans = 0;
        FOR(k, 0, n) {
            if (n - (x + y + 2LL * k) < z) break;
            ll res = 0;

            auto comb = [&](ll n, ll r) {
                ll ret = fac[n] * ifac[r];
                ret %= M;
                ret *= ifac[n - r];
                return ret % M;
            };

            res = comb(x + y + 2 * k, x + y + k) * comb(x + y + 2 * k, y + k);
            res %= M;
            
            ll rem = n - (x + y + 2 * k);
            ll bz = (rem - z) / 2;
            ll fz = rem - bz;

            res = res * comb(n - bz, fz) % M * comb(n, bz) % M;

            ans += res;
            ans %= M;
        }

        cout << ans << '\n';
    }

    return 0;
}