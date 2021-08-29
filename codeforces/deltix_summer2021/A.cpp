#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 101010;

int n;
double ans;

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
        ll c, d;
        cin >> c >> d;
        ll diff = abs(c - d);
        if (diff % 2 == 1) {
            cout << -1 << '\n';
        } else {
            int ans;
            if (diff == 0) {
                if (c == 0 && d == 0)
                    ans = 0;
                else
                    ans = 1;
            } else {
                ans = 2;
            }
            cout << ans << '\n';
        }
    }
    return 0;
}