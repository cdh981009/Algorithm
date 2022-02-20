#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 201010;

int n, m;
ll x[N], y[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    while (tc--) {
        cin >> n >> m;
        FOR(i, 0, n) cin >> x[i] >> y[i];
        ll ans = x[0];
        ll v = 0, w = 0;
        FOR(i, 0, n) {
            ll nv = v + x[i] * y[i];
            if (nv < 0 && v > 0) {
                ll yp = -v / x[i];
                ll nw = w + v * yp + x[i] * yp * (yp + 1) / 2;
                ans = max(ans, nw);
                // cout << nv << ' ' << v << ' ' << yp << ' ' << nw << '\n';
            }
            w = w + v * y[i] + x[i] * y[i] * (y[i] + 1) / 2;
            v = nv;
            ans = max(ans, w);
        }

        cout << ans << '\n';
    }
    return 0;
}