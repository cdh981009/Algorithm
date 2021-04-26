#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 2e5 + 10;
constexpr int M = 1e9 + 7;

using ll = long long;

string n;
int m;

int dp[10][N];

ll getDp(int d, int x) {
    int& ref = dp[d][x];
    if (ref != -1)
        return ref;
    ref = 1;

    if (x >= 10 - d) {
        ref = (getDp(1, x - (10 - d)) + getDp(0, x - (10 - d))) % M;
    }

    return ref;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof(int) * N * 10);

    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        ll ans = 0;
        FOR(i, 0, n.size()) {
            ans += getDp(n[i] - '0', m);
            ans %= M;
        }
        cout << ans << '\n';
    }
    return 0;
}