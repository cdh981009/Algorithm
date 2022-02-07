#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 2e5 + 10;
int a[N];
int cnt[N];
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
        int n, k;
        cin >> n >> k;
        memset(cnt, 0, sizeof(cnt));
        FOR(i, 0, n) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        FOR_(i, 1, n)
            cnt[i] += cnt[i - 1];
        int x, y, xi, yi;;
        x = xi = 0;
        y = yi = 0;
        int minR = n + 1;
        
        auto inRange = [&](int x, int y) {
            if (y < x) return 0;

            return cnt[y] - (x - 1 >= 0 ? cnt[x - 1] : 0);
        };

        for (;xi <= n; ++xi) {
            while (yi <= n) {
                int res = inRange(xi, yi);
                if (res - (n - res) >= k)
                    break;
                yi++;
            }
            if (yi > n) break;

            int range = yi - xi;
            if (minR > range) {
                minR = range;
                x = xi;
                y = yi;
            }
        }

        // ans
        cout << x << ' ' << y << '\n';
        int l, r;
        l = r = 0;
        int irg, org;
        irg = org = 0;
        FOR(i, 0, n) {
            if (a[i] < x || a[i] > y)
                org++;
            else
                irg++;
            
            if (irg > org && k > 1) {
                cout << l + 1 << ' ' << i + 1 << '\n';
                irg = org = 0;
                l = i + 1;
                k--;
            }
        }
        cout << l + 1 << ' ' << n << '\n';

    }
    return 0;
}