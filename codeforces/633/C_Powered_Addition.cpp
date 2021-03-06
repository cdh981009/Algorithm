#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

#define INF 1000000000
int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        int maxVal = -INF;
        int maxDiff = 0;
        FOR(i, 0, n) {
            int x; cin >> x;
            if (maxVal < x) {
                maxVal = x;
            } else {
                maxDiff = max(maxDiff, maxVal - x);
            }
        }
        //cout << maxDiff << endl;
        int ans = 0;
        for (int i = 0; i <= 30; ++i) {
            if (maxDiff & (1 << i))
                ans = max(ans, i + 1);
        }
        cout << ans << "\n";
    }
    return 0;
}