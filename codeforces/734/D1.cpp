#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 201010;

int n, m, k;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n >> m >> k;
        bool ans = true;

        if (m == 1) {
            ans = (k == 0);
        } else if (n == 1) {
            ans = (k == (n * m) / 2);
        } else {
            if (n % 2 == 1) {
                swap(n, m);
                k = (n * m) / 2 - k;
            }
            // n is always even number
            if (k % 2) {
                ans = false;
            } else {
                int x = m;
                int y = k;
                while (y > 0) {
                    if (x == 1) {
                        ans = false;
                        break;
                    }

                    y -= min(n, y);
                    x -= 2;
                }
            }
        }

        cout << (ans ? "YES" : "NO") << '\n';
    }
    return 0;
}