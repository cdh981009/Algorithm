#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 101010;

int n;
int odd;
bool arr[N];

int solve() {
    // odd goes first
    if (n % 2 && 2 * odd < n) {
        odd = n - odd;
        FOR(i, 0, n) {
            arr[i] = !arr[i];
        }
    }

    int ans = 0;
    int ind = 0;
    FOR(i, 0, n) {
        if (arr[i]) {
            ans += abs(i - ind);
            ind += 2;
        }
    }

    return ans;
}

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
        odd = 0;
        FOR(i, 0, n) {
            int x; cin >> x;
            odd += x % 2;
            arr[i] = x % 2;
        }
        int diff = abs(n - 2 * odd);
        if (diff == 0 || diff == 1) {
            int ans = solve();
            if (n % 2 == 0) {
                FOR(i, 0, n)
                    arr[i] = !arr[i];
                ans = min(ans, solve());
            }
            cout << ans << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}