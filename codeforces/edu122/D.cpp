#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 1010;
constexpr int K = 1e6 + 1;

int ans;
pii arr[N];
int n, k;
int op[N];
int dp[K];

// 1에서 x로 가는데 드는 최소 operation

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    FOR(i, 0, N)
        op[i] = 1e6 + 10;
    op[1] = 0;

    FOR(i, 1, N) {
        FOR_(j, 1, i) {
            int x = i + i / j;
            if (x >= N) continue;

            op[x] = min(op[x], 1 + op[i]);
        }
    }

    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n >> k;
        k = min(12 * n + 10, k);
        
        FOR(i, 0, n) {
            cin >> arr[i].first;
            arr[i].first = op[arr[i].first];
            //cout << arr[i].first << ' ';
        }
        FOR(i, 0, n) {
            cin >> arr[i].second;
        }

        memset(dp, 0, sizeof(dp));

        for (int i = n - 1; i >= 0; --i) {
            for (int j = k; j >= 0; --j) {
                if (j - arr[i].first >= 0)
                    dp[j] = max(dp[j], dp[j - arr[i].first] + arr[i].second);
            }
        }

        ans = dp[k];
        
        cout << ans << '\n';
    }
    return 0;
}