#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 10;
int n, m;
int ans;

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
        cin >> n >> m;

        m++;
        ans = 0;

        bool s = true;
        for (int i = 30; i >= 0; --i) {
            int x = (n & (1 << i));
            int y = (m & (1 << i));
            if (!x && y && s) {
                ans |= (1 << i);
            }
            if (x && !y) {
                s = false;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}