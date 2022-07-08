#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 7)
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep_(i, a, b) for (int i = (a); i <= (b); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)
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

constexpr int N = 201010;
constexpr int M = 100;

ll n, m, k, q, ans;
ll a[N], b[N];

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
        cin >> n >> m;
        rep(i, 0, m) {
            cin >> a[i];
            a[i]--;
        }
        ll mx = 401010;
        ll x = 0;

        auto op = [&](int t) {
            memset(b, 0, sizeof(ll) * n);
            ll undone = 0;
            rep(i, 0, m) {
                if (b[a[i]] + 1 <= t)
                    b[a[i]] += 1;
                else
                    undone += 2;
            }
            bool pos = false;
            rep(i, 0, n) {
                while (b[i] + 2 <= t) {
                    b[i] += 2;
                    undone -= 2;
                    if (undone <= 0) break;
                }
                if (undone <= 0) break;
            }
            if (undone > 0) return false;
            return true;
        };

        for (ll step = mx; step >= 1; step /= 2) {
            while (x + step < mx && !op(x + step))
                x += step;
        }

        cout << x + 1 << '\n';
    }

    return 0;
}