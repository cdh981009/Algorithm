#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 100;
int a[N], b[N];

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
        FOR(i, 0, n) cin >> a[i];
        FOR(i, 0, n) cin >> b[i];
        int mx, mn;
        mn = -1;
        mx = -1;
        FOR(i, 0, n) {
            mx = max(mx, max(a[i], b[i]));
            mn = max(mn, min(a[i], b[i]));
        }
        ans = mx * mn;
        cout << ans << '\n';
    }
    return 0;
}