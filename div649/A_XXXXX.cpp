#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

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
        vector<int> arr(n);
        int sum = 0;
        FOR(i, 0, n) {
            int in; cin >> in;
            arr[i] = in;
            sum += in;
        }
        int ans = (sum % x == 0) ? -1 : n;
        int left = sum;
        FOR(i, 0, n) {
            left -= arr[i];
            if (left % x != 0) {
                ans = max(ans, n - i - 1);
                break;
            }
        }
        int right = sum;
        FOR(i, 0, n) {
            right -= arr[n - i - 1];
            if (right % x != 0) {
                ans = max(ans, n - i - 1);
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}