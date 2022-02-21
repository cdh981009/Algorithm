#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;

constexpr int N = 1e6 + 10;
constexpr int M = 1e9 + 7;

ll a[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, k; cin >> n >> k;
    ll sum = 0;
    FOR(i, 0, n) {
        cin >> a[i];
        sum += a[i];
        a[i] %= k;
    }

    if (sum % k) {
        cout << "blobsad\n";
    } else {
        ll ans = 0;
        FOR(i, 0, n) {
            a[i] = (a[i] + k) % k;
            if (a[i] < k - a[i]) { // 내가 움직이는게 더 이득
                ans += a[i];
            } else { // 누군가 움직여 오는게 더 이득
                ans += k - a[i];
            }
            a[i+1] += a[i];
        }

        cout << ans << '\n';
    }

    return 0;
}