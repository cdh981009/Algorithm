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

    int n; cin >> n;
    vector<int> a(n);
    FOR(i, 0, n) cin >> a[i];
    int ans = max(a[0], a[n-1]);
    FOR(i, 1, n - 1) {
        ans = max(ans, a[i] + min(a[i-1], a[i+1]));
    }

    cout << ans << '\n';

    return 0;
}