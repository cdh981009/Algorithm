#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 3000101;
constexpr int M = 1e9 + 7;

int q, n;
int co[N];
int ans[N];
int arr[N];
int f[N], invf[N];

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

ll inv(ll x) {
    return modpow(x, M - 2);
}

ll choose(ll n, ll r) {
    if (n < 0 || r > n || r < 0)
        return 0;

    ll ret = f[n];
    ret *= invf[n - r];
    ret %= M;
    ret *= invf[r];
    ret %= M;
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    f[0] = 1;
    FOR(i, 1, N) {
        f[i] = ((ll)f[i - 1] * i) % M;
    }

    invf[N - 1] = inv(f[N - 1]);
    for (int i = N - 2; i >= 0; --i) {
        invf[i] = ((ll)invf[i + 1] * (i + 1)) % M;
    }

    cin >> n >> q;

    // numerator
    co[1] = -3;
    co[2] = -3;
    co[3] = -1;

    FOR(i, 1, N) {
        ll x = choose(3 * n + 3, i);
        co[i] = (co[i] + x + M) % M;
    }
    // divide denominator
    for (int i = N - 3; i >= 1; --i) {
        ans[i - 1] = co[i + 2];
        co[i + 1] = (co[i + 1] - 3LL * ans[i - 1] + 3LL * M) % M;
        co[i]     = (co[i]     - 3LL * ans[i - 1] + 3LL * M) % M;
    }

    FOR(i, 0, q) {
        cin >> arr[i];
    }
    FOR(i, 0, q) {
        cout << ans[arr[i]] << '\n';
    }

    return 0;
}