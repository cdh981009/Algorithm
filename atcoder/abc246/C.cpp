#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep_(i, a, b) for (int i = (a); i <= (b); ++i)
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

ll n, k, x;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k >> x;
    vl a(n);
    rep(i, 0, n) cin >> a[i];

    ll ans = 0;

    rep(i, 0, n) {
        ll kp = a[i] / x;
        ll kr = min(k, kp);
        ans += a[i] - kr * x;
        a[i] -= kr * x;
        k -= kr;
    }

    if (k > 0) {
        sort(a.rbegin(), a.rend());
        rep(i, 0, n) {
            k -= 1;
            ans -= a[i];
            if (k == 0) break;
        }
    }


    cout << ans << '\n';

    return 0;
}