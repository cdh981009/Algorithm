#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define fi first
#define se second
#define rep(i, a, b) for (ll i = (a); i < (b); ++i)
#define rep_(i, a, b) for (ll i = (a); i <= (b); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pii>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 101010;
constexpr int M = 100;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;

    ll ans = 1e18 + 100;

    if (n == 0)
        ans = 0;
    else {
        rep_(a, 0, 1e6) {
            // do parametric
            ll mx = 1e6;
            ll b = 0;
            for (ll step = mx; step >= 1; step /= 2) {
                while (b + step <= mx && (a * a + (b + step) * (b + step)) * (a + (b + step)) < n)
                    b += step;
            }

            b++;
            if ((a * a + b * b) * (a + b) >= n)
                ans = min(ans, (a * a + b * b) * (a + b));
        }
    }

    cout << ans << '\n';

    return 0;
}