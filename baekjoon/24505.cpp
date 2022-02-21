#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;

constexpr int N = 1e5 + 10;
constexpr int M = 12;
constexpr int MOD = 1e9 + 7;

int n;
int a[N];
ll bit[M][N];
ll dp[N][M];

void add(int j, int i, int v) {
    i++;
    while (i <= n + 2) {
        bit[j][i] += v;
        bit[j][i] = (bit[j][i] + MOD) % MOD;
        i += (i & -i);
    }
}

int sum(int j, int i) {
    ll ret = 0;
    i++;
    while (i >= 1) {
        ret += bit[j][i];
        ret %= MOD;
        i -= (i & -i);
    }

    return ret;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 0, n) cin >> a[i];

    ll ans = 0;
    FOR(i, 0, n) {
        FOR_(j, 1, 11) {
            ll &x = dp[i][j];
            if (j == 1) {
                x = 1;
            } else {
                x = sum(j, a[i]);
            }

            if (j < 11) {
                add(j + 1, a[i] + 1, x);
            } else {
                ans += x;
                ans %= MOD;
            }
        }
    }
    
    cout << ans << '\n';

    return 0;
}