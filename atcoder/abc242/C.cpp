#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pii>;

constexpr int N = 1010100;
constexpr int M = 998244353;

int n;
ll dp[N][10];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    memset(dp, 0, sizeof(dp));

    ll ans = 0;
    FOR_(i, 1, 9)
        dp[0][i] = 1;

    FOR(j, 1, n) {
        FOR_(i, 1, 9) {
            FOR_(k, -1, 1) {
                if (i + k == 0 || i + k == 10) continue;
                dp[j][i] += dp[j - 1][i + k];
                dp[j][i] %= M;
            }
        }
    }

    FOR_(i, 1, 9)
    ans = (ans + dp[n - 1][i]) % M;

    cout << ans << '\n';

    return 0;
}