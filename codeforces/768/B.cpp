#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 2e5 + 10;

int a[N];

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
        ans = 0;
        while (true) {
            int cnt = 1;
            for (int i = n - 2; i >= 0; --i) {
                if (a[i] == a[n - 1]) cnt++;
                else break;
            }

            if (cnt == n) break;
            else {
                int i = n - cnt - 1;
                while (cnt-- && i >= 0) {
                    a[i] = a[n - 1];
                    i--;
                }
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}