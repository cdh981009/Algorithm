// 1657: 두부장수 장홍준
// https://www.acmicpc.net/problem/1648
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 14;
constexpr int X = (1 << N);

const int cost[5][5] = {
        10, 8, 7, 5, 1,
        8, 6, 4, 3, 1,
        7, 4, 3, 2, 1,
        5, 3, 2, 2, 1,
        1, 1, 1, 1, 0};

int arr[N * N];
int dp[N * N][X];
int n, m;

int cutTufu(int ind, int state) {
    if (ind > n * m)
        return -INF;
    if (ind == n * m)
        return state == 0 ? 0 : -INF;

    int& ref = dp[ind][state];

    if (ref != -1)
        return ref;

    ref = 0;

    if (state & 1) {
        ref = cutTufu(ind + 1, state >> 1); // 이미 다른 조각에 포함됨
    } else {
        // 1. 안자르고 버림
        ref = cutTufu(ind + 1, state >> 1);
        // 2. 세로로 2x1 자름
        if (ind + m < n * m)
            ref = max(ref,
                    cost[arr[ind]][arr[ind + m]] +
                            cutTufu(ind + 1, (state >> 1) | (1 << (m - 1))));
        // 3. 가로로 2x1 자름
        if (ind % m != m - 1 && !(state & (1 << 1))) {
            ref = max(ref,
                    cost[arr[ind]][arr[ind + 1]] +
                            cutTufu(ind + 2, state >> 2));
        }
    }

    return ref;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    memset(dp, -1, sizeof(int) * X * N * N);

    scanf("%d %d", &n, &m);
    FOR(i, 0, n * m) {
        scanf(" %c", &arr[i]);
        arr[i] -= 'A';
        if (arr[i] == 5)
            --arr[i];
    }

    printf("%d", cutTufu(0, 0));

    return 0;
}