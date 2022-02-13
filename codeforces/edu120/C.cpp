#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 2e5 + 10;
constexpr int M = 998244353;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        ll n, k, ans;
        vector<ll> a;
        vector<ll> pSum;
        cin >> n >> k;
        a = vector<ll>(n);
        pSum = vector<ll>(n);

        FOR(i, 0, n)
            cin >> a[i];

        if (n == 1) {
            if (a[0] <= k) ans = 0;
            else ans = a[0] - k;
        } else {
            sort(a.rbegin(), a.rend());
            pSum[0] = 0;
            FOR(i, 1, n)
            pSum[i] = a[i - 1] + pSum[i - 1];

            ll tSum = pSum.back();
            ans = INT64_MAX;
            ll v = a.back();
            // cout << v << '\n';
            // 가장 큰 i개를 a[n - 1]으로 바꿀 떄 a[n - 1]을 얼마나 줄여야 하는가?
            FOR_(i, 0, n - 1) {
                auto floor = [](ll a, ll b) {
                    ll ret = a / b;
                    if (ret * b > a) ret--;
                    return ret;
                };

                ll x = floor((k - tSum + pSum[i]), (i + 1));
                x = v - x;
                if (x < 0) x = 0;
                // cout << x << ' ' << i << '\n';
                // cout <<  (v - x) * (i + 1) + tSum - pSum[i] << '\n';
                ans = min(ans, x + i);
            }
        }

        cout << ans << '\n';
    }
    return 0;
}