#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;

constexpr int N = 1e5;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;
    vector<int> a(2 * n);
    FOR(i, 0, n) {
        cin >> a[i];
        a[i + n] = a[i];
    }

    FOR(i, 1, 2 * n) {
        a[i] += a[i-1];
    }

    int ans = 0;
    FOR(i, k - 1, 2 * n) {
        ans = max(ans, a[i] - (i - k >= 0 ? a[i - k] : 0));
    }

    cout << ans << '\n';

    return 0;
}