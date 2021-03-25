// 11402: 이항 계수 4
// https://www.acmicpc.net/problem/11402
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int M = 2010;

long long n, k, m;

int dp[M][M];

int c(int n, int k) {
    if (k > n)
        return 0;
    // c(n, k) = c(n - 1, k - 1) + c(n - 1, k);
    if (k * 2 > n)
        k = n - k;

    if (k == 0) {
        return 1;
    }

    if (dp[n][k] != -1)
        return dp[n][k];

    return dp[n][k] = (c(n - 1, k - 1) + c(n - 1, k)) % m;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof(int) * M * M);

    cin >> n >> k >> m;

    // Lucas' theorem
    // (m, n) = PI(mi, ni) (mod p)
    // when m = (m0 * p^0) + (m1 * p^1) + ... + (mk * p^k);
    //      n = (n0 * p^0) + (n1 * p^1) + ... + (nk * p^k);
    long long ans = 1;
    while (true) {
        int ni, ki;
        ni = n % m;
        ki = k % m;
        n /= m;
        k /= m;
        ans *= c(ni, ki);
        ans %= m;

        if (n == 0 && k == 0)
            break;
    }

    cout << ans << '\n';

    return 0;
}