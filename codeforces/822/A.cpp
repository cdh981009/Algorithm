#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 7)
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep_(i, a, b) for (int i = (a); i <= (b); ++i)
#define repr_(i, a, b) for (int i = (a); i >= (b); --i)
#define printYN(pos) cout << (pos ? "YES" : "NO") << '\n'
#define printPOS(pos) cout << (pos ? "POSSIBLE" : "IMPOSSIBLE") << '\n'

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 300;
constexpr int M = 100;

ll n, m, k, q, ans;
ll a[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        rep(i, 0, n) cin >> a[i];

        ll ans = 1e14;

        rep(i, 0, n)
            rep(j, i + 1, n)
                rep(k, j + 1, n) {
                    ans = min(ans, abs(a[i] - a[j]) + abs(a[i] - a[k]));
                    ans = min(ans, abs(a[i] - a[j]) + abs(a[j] - a[k]));
                    ans = min(ans, abs(a[k] - a[j]) + abs(a[i] - a[k]));
                }

        cout << ans << '\n';
    }

    return 0;
}