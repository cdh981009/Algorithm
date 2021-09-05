#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 101;

int s;
int n;
int ans[N];

void solve() {
    ll t = 1;
    while (t <= s) {
        t *= 10;
    }
    t /= 10;
    int cnt = 0;
    while (cnt < n) {
        if (n - cnt - 1 <= s - t) {
            ans[cnt++] = t;
            s -= t;
        } else {
            t /= 10;
        }
    }
    ans[0] += s;
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
        cin >> s >> n;
        memset(ans, 0, sizeof(int) * n);
        solve();
        FOR(i, 0, n) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}