// 1010: 다리 놓기
// https://www.acmicpc.net/problem/1010
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 31;
int dp[N][N];

int c(int n, int r) {
    // c(n , r) == c(n, n - r)
    if (r > n - r)
        r = n - r;

    if (r == 0)
        return 1;
    if (r == 1)
        return n;

    int& ref = dp[n][r];
    if (ref != -1)
        return ref;

    return ref = c(n - 1, r - 1) + c(n - 1, r);
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof(int) * N * N);

    int tc; cin >> tc;
    while (tc--) {
        int a, b; cin >> a >> b;
        cout << c(b, a) << '\n';
    }

    return 0;
}