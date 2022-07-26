#include <bits/stdc++.h>

using namespace std;

#define INF (1e9+7)
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
ll arr[N];

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
        m *= 2;
        vector<pll> diff;
        vector<pll> vec;
        rep(i, 0, n) {
            ll x, p;
            cin >> x >> p;
            x *= 2;
            p *= 2;
            diff.push_back({x-p, 1});
            diff.push_back({x, -2});
            diff.push_back({x+p, 1});
            vec.push_back({x, p});
        }
        sort(diff.begin(), diff.end());

        ll d = 0, a = 0;
        ll lst = -INF;
        pll v = {0, -3LL * INF};

        auto intersect = [&](pll a, pll b) -> pll {
            ll nx = max(a.first + a.second, b.first + b.second);
            ll ny = max(-a.first + a.second, -b.first + b.second);
            return {(nx - ny) / 2, (nx + ny) / 2};
        };

        for (auto& p : diff) {
            if (p.first != lst) {
                a = a + (p.first - lst) * d;
                lst = p.first;

                if (a > m) {
                    v = intersect(v, {p.first, a-m});
                }
            }
            d += p.second;
        }

        string ans;
        for (auto& p: vec) {
            if (intersect(v, p) == p) ans += '1';
            else ans += '0';
        }

        cout << ans << '\n';
    }

    return 0;
}