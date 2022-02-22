#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 101010;
constexpr int M = 1e9 + 7;

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
        int n, x; cin >> n >> x;
        vector<int> a(n + 1);
        FOR_(i, 1, n) cin >> a[i];
        vector<int> mx(n + 1, INT32_MIN);

        FOR_(i, 1, n) {
            a[i] += a[i-1];
        }

        mx[0] = 0;
        FOR_(i, 1, n) {
            FOR_(j, i, n) {
                int s = a[j] - a[i - 1];
                mx[j - i + 1] = max(mx[j - i + 1], s);
            }
        }

        FOR_(k, 0, n) {
            int ans = -INF;
            FOR_(i, 0, n) {
                int res = mx[i];
                res += x * min(i, k);
                ans = max(ans, res);
            }
            cout << ans << ' ';
        }
        cout << '\n';
        
    }

    return 0;
}