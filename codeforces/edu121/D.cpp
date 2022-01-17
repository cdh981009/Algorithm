#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 2e5 + 10;

int ans;
int arr[N];
int arr2[N];
int n;

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
        cin >> n;
        memset(arr, 0, sizeof(int) * (n + 2));
        FOR(i, 0, n) {
            int x; cin >> x;
            arr[x]++;
        }
        memcpy(arr2, arr, sizeof(int) * (n + 2));
        FOR_(i, 1, n + 1)
            arr[i] += arr[i - 1];

        int ans = INF;
        
        auto op = [](int x) {
            int ret = 1;
            while (ret < x)
                ret *= 2;
            return ret - x;
        };

        int yn = 0;
        for (int y = n + 1; y >= 1; --y) {
            yn += arr2[y];
            int ycnt = op(yn);

            for (int s = 1; s < (1 << 20); s *= 2) {
                auto it = upper_bound(arr, arr + y, s);
                it--;
                int res = ycnt;
                res += op(*it);
                res += op(n - yn - *it);
                ans = min(ans, res);
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}