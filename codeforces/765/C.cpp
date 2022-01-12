#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 500;
constexpr int M = 1e4 + 10;

int ans;
int a[N], d[N];
int dp[N][N];

int n, l, k;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> l >> k;

    int p = 0;
    FOR(i, 0, n) {
        int x;
        cin >> x;
        if (i > 0)
            d[i - 1] = x - p;
        p = x;
    }
    d[n - 1] = l - p;

    FOR(i, 0, n) {
        cin >> a[i];
    }

    for (int i = n - 1; i >= 1; --i) {
        for (int j = i - 1; j >= 0; --j) {
            for (int m = k; m >= 0; --m) {
                int res;
                res = d[i] * a[i] + dp[i][m];
                
                if (m > 0)
                    res = min(res, d[i] * a[j] + dp[j][m - 1]);

                dp[j][m] = res;
            }
        }
    }

    cout << d[0] * a[0] + dp[0][k] << '\n';

    return 0;
}