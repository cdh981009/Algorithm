#include <bits/stdc++.h>

using namespace std;

#define INF 6e4
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e5 + 20;

using ll = long long;

int n;
int l[N], r[N], c[N];

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
        cin >> n;
        FOR(i, 0, n) {
            cin >> l[i] >> r[i] >> c[i];
        }
        int li, ri, mi, ml;
        FOR(i, 0, n) {
            if (i == 0) {
                li = ri = i;
                ml = r[i] - l[i];
                mi = i;
            } else {
                if (l[li] > l[i] || (l[li] == l[i] && c[li] > c[i])) {
                    li = i;
                }
                if (r[ri] < r[i] || (r[ri] == r[i] && c[ri] > c[i])) {
                    ri = i;
                }
                if (r[i] - l[i] > ml || (ml == r[i] - l[i] && c[i] < c[mi])) {
                    mi = i;
                    ml = r[i] - l[i];
                }
            }

            int ans;
            int lc = c[li];
            int rc = c[ri];

            if (l[li] == l[ri] && r[ri] == r[li])
                ans = min(rc, lc);
            else if (l[li] == l[ri])
                ans = rc;
            else if (r[ri] == r[li])
                ans = lc;
            else
                ans = lc + rc;

            if (r[ri] - l[li] == ml)
                ans = min(ans, c[mi]);

            cout << ans << '\n';
        }
    }

    return 0;
}