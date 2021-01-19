// 1648: 격자판 채우기
// https://www.acmicpc.net/problem/1648
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 14;
constexpr int X = (1 << N);
constexpr int M = 9901;

int dp[N * N][X];
int n, m;

int fillGrid(int ind, int state) {
    if (ind > n * m)
        return 0;
    if (ind == n * m)
        return state == 0;

    int& ref = dp[ind][state];

    if (ref != -1)
        return ref;

    if (state & 1) {
        ref = fillGrid(ind + 1, state >> 1);
    } else {
        ref = fillGrid(ind + 1, (state >> 1) | (1 << (m - 1))); // 아래로
        if (ind % m != m - 1 && !(state & (1 << 1))) { // 옆으로
            ref += fillGrid(ind + 2, state >> 2);
        }
    }

    return ref %= M;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    memset(dp, -1, sizeof(int) * X * N * N);

    scanf("%d %d", &n, &m);

    printf("%d", fillGrid(0, 0));

    return 0;
}