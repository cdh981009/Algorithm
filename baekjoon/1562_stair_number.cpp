// 1562: 계단 수
// https://www.acmicpc.net/problem/1562
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

// bit dp
constexpr int N = 100;
constexpr int X = (1 << 10);
constexpr int D = 10;
constexpr int M = 1e9;

int n;
int dp[N][X][D];

int count(int i, int status, int x) {
    int& ref = dp[i][status][x];

    if (ref != -1)
        return ref;

    status |= (1 << x);

    if (i == n - 1) {
        return ref = (status == X - 1 ? 1 : 0);
    } else {
        ref = 0;

        if (x > 0) {
            ref += count(i + 1, status, x - 1);
            ref %= M;
        }

        if (x < 9) {
            ref += count(i + 1, status, x + 1);
            ref %= M;
        }

        return ref;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof(int) * N * X * D);
    cin >> n;

    int cnt = 0;
    FOR_(x, 1, 9) {
        cnt += count(0, 0, x);
        cnt %= M;
    }
    cout << cnt << '\n';

    return 0;
}