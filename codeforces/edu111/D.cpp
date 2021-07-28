#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 201010;
constexpr int M = 1e9 + 7;

using ll = long long;

int n, l, r;
ll ans;
int fact[N];
int invFact[N];

int binom(int n, int r) {
    if (r > n || r < 0 || n < 0)
        return 0;
    ll x;

    x = fact[n];
    x *= invFact[n - r];
    x %= M;
    x *= invFact[r];
    x %= M;

    return x;
}

int modpow(int a, int b) {
    ll ret = 1;
    ll base = a;
    while (b) {
        if (b % 2 == 1) {
            ret *= base;
            ret %= M;
        }
        base *= base;
        base %= M;
        b /= 2;
    }

    return ret;
}

int modularInv(int a) {
    return modpow(a, M - 2);
}

void init() {
    fact[0] = 1;
    FOR(i, 1, N) {
        fact[i] = ((ll)fact[i - 1] * i) % M;
    }

    invFact[0] = 1;
    FOR(i, 1, N) {
        invFact[i] = ((ll)invFact[i - 1] * modularInv(i)) % M;
    }
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

    init();

    while (tc--) {
        cin >> n >> l >> r;
        ans = 0;

        // for len [1, k] every element chooses freely
        ll k = min(1 - l, r - n);
        ans += (ll)k * binom(n, n / 2);
        ans %= M;
        if (n % 2) {
            ans *= 2;
            ans %= M;
        }

        while (true) {
            k++;
            ll x = max((ll)0, l - 1 + k);
            ll y = min((ll)n + 1, r + 1 - k);
            if (x >= y)
                break;
            ll z = y - x - 1;
            if (n % 2) {
                ans += binom(z, n / 2 - x);
                ans %= M;
                ans += binom(z, n / 2 - x + 1);
                ans %= M;
            } else {
                ans += binom(z, n / 2 - x);
                ans %= M;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}