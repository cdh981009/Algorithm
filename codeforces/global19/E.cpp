#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 301010;

int n, m;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n >> m;
        ll ans = 0;
        map<int, int> mp;
        set<pii> bp;
        map<int, set<int>> buckets;

        FOR(i, 0, n) {
            int x; cin >> x;
            mp[x]++;
        }

        FOR(i, 0, m) {
            int x, y;
            cin >> x >> y;
            bp.insert({x, y});
            bp.insert({y, x});
        }

        for (auto &[x, cntx] : mp) {
            for (auto &[cnty, yset] : buckets) {
                auto it = yset.rbegin();
                while (it != yset.rend()) {
                    int y = *it;
                    if (bp.count({x, y}) == 0) {
                        //cout << x << ' ' << y << ' ' << cntx << ' ' << cnty << ' ' << ((ll)x + y) * ((ll)cntx + cnty) << '\n';
                        ans = max(ans, ((ll)x + y) * ((ll)cntx + cnty));
                        break;
                    }
                    it++;
                }
            }
            buckets[cntx].insert(x);
        }

        cout << ans << '\n';
    }
    return 0;
}