#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 100;
constexpr int M = 100;

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
        int n, ans;
        cin >> n;
        vector<int> a(n);
        FOR(i, 0, n) cin >> a[i];
        ans = 0;
        FOR(i, 1, n - 1) {
            if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
                a[i + 1] = max(a[i], i + 2 < n ? a[i + 2] : 0);
                ans++;
            }
        }
        cout << ans << '\n';
        for (auto &x : a) {
            cout << x << ' ';
        }
        cout << '\n';
    }
    return 0;
}