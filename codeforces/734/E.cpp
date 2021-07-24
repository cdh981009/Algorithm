#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 2010;

int n, k;
int arr[N];
int dp[N][N];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n >> k;
        FOR(i, 0, n) {
            cin >> arr[i];
        }

        int ans = N;

        memset(dp, 0, sizeof(int) * N * N);

        // dp[i][j]: 첫 i개의 원소만 볼 때, 이 중 j개의 원소만 남겼을 때 matching할 수 있는 원소의 수의 최대
        // dp[i-1][]를 알 때 dp[i][]를 계산. a[i-1]가 새로 추가된다.
        // 이 원소를 지우면 j는 변화 x. dp[i][j] = dp[i - 1][j].
        // 이 원소를 지우지 않으면, j += 1. a[i-1] == j 라면 추가한 원소가 새로 matching된다.
        // dp[i][j] = dp[i - 1][j - 1] + (a[i-1] == j)

        // dp[0][] = 0, dp[][0] = 0;
        // 따라서 dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + (a[i-1] == j));
        FOR_(i, 1, n) {
            FOR_(j, 1, n) {
                if (i < j)
                    continue;
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + (arr[i - 1] == j));
                if (dp[i][j] >= k) {
                    ans = min(ans, i - j);
                }
            }
        }

        if (ans == N)
            ans = -1;

        cout << ans << '\n';
    }
    return 0;
}