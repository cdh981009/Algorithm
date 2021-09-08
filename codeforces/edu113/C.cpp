#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 201010;
constexpr long long M = 998244353;

using ll = long long;
using pii = pair<int, int>;

int arr[N];
ll n;
ll ans;
ll fact[N];
ll ifact[N];

ll modpow(ll a, ll x) {
    ll ret = 1;
    ll base = a;

    while (x) {
        if (x % 2) {
            ret *= base;
            ret %= M;
        }
        base = (base * base) % M;
        x /= 2;
    }

    return ret;
}

ll inv(int x) {
    return modpow(x, M - 2);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fact[0] = 1;
    FOR(i, 1, N) {
        fact[i] = (fact[i - 1] * i) % M;
    }

    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        FOR(i, 0, n) {
            cin >> arr[i];
        }
        ans = 0;
        sort(arr, arr + n);
        
        int mx = arr[n - 1];
        int mxn = arr + n - lower_bound(arr, arr + n, mx);

        if (mxn >= 2) {
            ans = fact[n];
        } else {
            int nx = arr[n - 1 - mxn];
            int nxn = arr + n - lower_bound(arr, arr + n, nx) - mxn;

            if (nx + 1 == mx) {
                ans = (fact[n] * (1LL - inv(nxn + 1) + M)) % M;
            } else {
                ans = 0;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}