// 2169: 로봇 조종하기
// https://www.acmicpc.net/problem/2169
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1000;

int n, m;
int arr[N][N];
int dp[N][N][2];
bool memoi[N][N][2];

enum {
    LEFT,
    RIGHT
};

int getMax(int i, int j, int dir) {
    int &ref = dp[i][j][dir];

    if (memoi[i][j][dir])
        return ref;

    memoi[i][j][dir] = true;
    ref = -INF;

    if (i - 1 >= 0) {
        ref = max(ref, getMax(i - 1, j, LEFT));
        ref = max(ref, getMax(i - 1, j, RIGHT));
    }

    if (dir == LEFT && j - 1 >= 0) {
        ref = max(ref, getMax(i, j - 1, LEFT));
    }

    if (dir == RIGHT && j + 1 < m) {
        ref = max(ref, getMax(i, j + 1, RIGHT));
    }

    return ref += arr[i][j];
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            cin >> arr[i][j];
        }
    }

    dp[0][0][LEFT] = arr[0][0];
    memoi[0][0][LEFT] = true;

    cout << getMax(n-1, m-1, LEFT) << '\n';

    return 0;
}