#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 10)
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
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pii>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 201010;
constexpr int M = 100;

ll n, x, ans;
ll a[N];

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
        cin >> n >> x;
        ans = 0;
        rep(i, 0, n) {
            cin >> a[i];
        }
        ll mx = a[0] + x;
        ll mn = a[0] - x;
        rep(i, 0, n) {
            ll nmx = a[i] + x;
            ll nmn = a[i] - x;
            if (mx < nmn || mn > nmx) {
                ans++;
                mx = nmx;
                mn = nmn;
            } else {
                mx = min(mx, nmx);
                mn = max(mn, nmn);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}