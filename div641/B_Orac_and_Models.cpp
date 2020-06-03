#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        vector<int> dp(n + 1, 1);
        vector<int> arr(n + 1);
        FOR(i, 0, n) {
            int x; cin >> x;
            arr[i + 1] = x;
        }
        int ans = 0;
        for (int i = n; i >= 1; --i) {
            for (int j = i + i; j <= n; j += i) {
                if (arr[i] < arr[j]) {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
            ans = max(ans, dp[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}