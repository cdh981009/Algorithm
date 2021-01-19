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

bitset<X> memoi[X];
bitset<X> valid[X];
int dp[X][N];
int n, m;

bool getValid(int prev, int curr) {
    if (memoi[prev][curr])
        return valid[prev][curr];

    bool open = false;
    memoi[prev][curr] = 1;

    FOR(i, 0, m) {
        if (prev & (1 << i)) {
            if (open || (curr & (1 << i))) {
                return valid[prev][curr] = false;
            }
        } else if (curr & (1 << i)) {
            if (open) {
                return valid[prev][curr] = false;
            }
        } else {
            open = !open;
        }
    }

    if (open)
        return valid[prev][curr] = false;

    return valid[prev][curr] = true;
}

int fillGrid(int prev, int ind) {
    if (ind == n)
        return getValid(prev, (1 << m) - 1);

    int& ref = dp[prev][ind];

    if (ref != -1)
        return ref;

    ref = 0;

    FOR(i, 0, (1 << m)) {
        if (getValid(prev, i)) {
            ref += fillGrid(i, ind + 1);
            ref %= M;
        }
    }

    return ref;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    memset(dp, -1, sizeof(int) * X * N);

    scanf("%d %d", &n, &m);

    if (n < m)
        swap(n, m);

    printf("%d", fillGrid(0, 0));

    return 0;
}