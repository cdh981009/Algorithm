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

constexpr int N = 301010;
constexpr int M = 8e6 + 10;

ll n;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    rep(tc, 0, T) {
        cout << "Case #" << tc + 1 << '\n';
        cin >> n;
        ll ans = 0;
        map<int, vi> mx, my;
        vpii pos;
        rep(i, 0, n) {
            ll x, y;
            cin >> x >> y;
            mx[x].push_back(y);
            my[y].push_back(x);
            pos.push_back({x, y});
        }

        int ox, oy;
        ox = oy = -1;

        for (auto& [k, v] : mx)
            if (v.size() % 2) ox = k;

        for (auto& [k, v] : my)
            if (v.size() % 2) oy = k;

        for (auto& [k, v] : mx) {
            sort(v.begin(), v.end());

            bool f = false;
            ll prev;
            for (auto& y : v) {
                if (k == ox && y == oy) continue;
                if (!f) {
                    prev = y;
                    f = true;
                } else {
                    f = false;
                    ans += y - prev;
                }
            }
        }
        
        for (auto& [k, v] : my) {
            sort(v.begin(), v.end());

            bool f = false;
            ll prev;
            for (auto& x : v) {
                if (k == oy && x == ox) continue;
                if (!f) {
                    prev = x;
                    f = true;
                } else {
                    f = false;
                    ans += x - prev;
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}