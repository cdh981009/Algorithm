#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 361;
constexpr int M = 998244353;

ll ans;
ll n;

ll modpow(ll a, ll x) {
    ll ret = 1;
    ll base = a % M;
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

    cin >> n;

    ll inv = M - M / 2;
    //cout << t << '\n';
    ll x = 1;
    ll aux;

    while (true) {
        bool b = false;
        if (n / 10 < x) {
            aux = n - x + 1;
            b = true;
        } else {
            aux = 9 * x;
        }
        aux %= M;
        aux *= aux + 1;
        aux %= M;
        aux *= inv;
        aux %= M;

        ans += aux;
        ans %= M;
        if (b) break;
        x *= 10;
    }

    cout << ans << '\n';

    return 0;
}