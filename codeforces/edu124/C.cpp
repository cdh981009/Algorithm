#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define fi first
#define se second
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

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vl a(n), b(n);
        FOR(i, 0, n)
        cin >> a[i];
        FOR(i, 0, n)
        cin >> b[i];

        ll ans = 0;

        ll af = a[0], al = a[n - 1];
        ll bf = b[0], bl = b[n - 1];

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        auto get = [&](const vl& v, ll x) {
            auto it = lower_bound(v.begin(), v.end(), x);
            ll can1, can2;
            can1 = can2 = 3e9;
            if (it != v.end()) can1 = *it;
            if (it != v.begin()) can2 = *(it - 1);

            return min(abs(can1 - x), abs(can2 - x));
        };

        ll afm = get(b, af);
        ll alm = get(b, al);
        ll bfm = get(a, bf);
        ll blm = get(a, bl);

        // cout << ans << '\n';

        // two connect
        ans = min(abs(af - bl) + abs(al - bf), abs(af - bf) + abs(al - bl));
        // four connect
        ans = min(ans, afm + alm + bfm + blm);
        // three connect
        ans = min(ans, abs(af - bf) + alm + blm);
        ans = min(ans, abs(af - bl) + alm + bfm);
        ans = min(ans, abs(al - bl) + afm + bfm);
        ans = min(ans, abs(al - bf) + afm + blm);

        cout << ans << '\n';
    }

    return 0;
}