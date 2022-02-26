#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 100;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q; cin >> q;
    multiset<ll> s;
    FOR(i, 0, q) {
        ll c, x, k; cin >> c >> x;
        ll ans;
        if (c == 1) {
            s.insert(x);   
        } else if (c == 2) { // k th largest
            cin >> k;
            auto it = s.upper_bound(x);
            while (true) {
                if (it == s.begin()) {
                    ans = -1;
                    break;
                } else {
                    --it;
                    ans = *it;
                }
                k--;
                if (k == 0) break;
            }
            cout << ans << '\n';
        } else { // k th smallest
            cin >> k;
            auto it = s.lower_bound(x);
            while (it != s.end()) {
                ans = *it;
                k--;
                if (k == 0) break;
                ++it;
                if (it == s.end()) break;
            }

            if (it == s.end()) ans = -1;
            cout << ans << '\n';

        }
    }

    
    return 0;
}