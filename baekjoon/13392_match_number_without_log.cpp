// 13392: 방법을 출력하지 않는 숫자 맞추기
// https://www.acmicpc.net/problem/13392
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 10000;
constexpr int D = 10;

int n;
int from[N];
int to[N];
int dp[D][N];

int getMin(int spin, int i) {
    if (i == n)
        return 0;
    
    int& ref = dp[spin][i];

    if (ref != -1)
        return ref;

    ref = INF;

    FOR(j, 0, 10) {
        int newSpin = spin + j;
        newSpin %= 10;
        int curr = (from[i] + newSpin) % 10;
        int diff = curr - to[i];
        if (diff < 0) diff += 10;

        ref = min(ref, getMin(newSpin, i + 1) + diff + j);
    }

    return ref;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);

    FOR(i, 0, n) {
        scanf("%1d", &from[i]);
    }

    FOR(i, 0, n) {
        scanf("%1d", &to[i]);
    }

    memset(dp, -1, sizeof(int) * D * N);

    printf("%d\n", getMin(0, 0));

    return 0;
}