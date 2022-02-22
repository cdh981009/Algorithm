#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 1e6 + 10;
constexpr int M = 1e9 + 7;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll k, q;
    cin >> k >> q;
    vector<pair<ll, ll>> p;
    
    for (ll i = 2; i * i <= k && k > 1; ++i) {
        ll element = 1;
        while (k > 1 && k % i == 0) {
            k /= i;
            element *= i;
        }
        if (element > 1) {
            p.push_back({i, element});
        }
    }

    if (k > 1) {
        p.push_back({k, k});
    }

    FOR(i, 0, q) {
        ll a; cin >> a;
        ll ans = 2;
        for (auto [prime, element] : p) {
            ll x = a;
            ll j = 0;

            while (x %= element) {
                j += prime;
                x *= j % element;
            }

            ans = max(j, ans);
        }
        cout << ans << ' ';
    }
    cout << '\n';

    return 0;
}