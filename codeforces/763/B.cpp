#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 1e3;
pii arr[N];

set<pii> m;

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
        m.clear();
        int n; cin >> n;
        FOR(i, 0, n) {
            int l, r;
            cin >> l >> r;
            m.insert({l, r});
        }

        for (auto &[l, r] : m) {
            int x;
            if (l == r)
                x = l;

            else { 
                FOR_(d, l, r) {
                    
                    if (l == d) {
                        if (m.count({d + 1, r})) {
                            x = d;
                            break;
                        }
                    } else if (r == d) {
                        if (m.count({l, d - 1})) {
                            x = d;
                            break;
                        }
                    } else {
                        if (m.count({l, d - 1}) && m.count({d + 1, r})) {
                            x = d;
                            break;
                        }
                    }


                }
            }

            cout << l << ' ' << r << ' ' << x << '\n';
        }
    }
    return 0;
}