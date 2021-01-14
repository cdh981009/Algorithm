// 1311: 할 일 정하기
// https://www.acmicpc.net/problem/1311
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

const int N = 20;
const int X = 1 << N;

int n;
int dp[X][N];
int arr[N][N];

int getDp(int state, int ind) {
    if (state == 0)
        return 0;

    int &ref = dp[state][ind];

    if (ref != -1)
        return ref;

    ref = INF;
    FOR(i, 0, n) {
        if (state & (1 << i)) {
            ref = min(ref, getDp(state ^ (1 << i), ind - 1) + arr[i][ind]);
        }
    }

    return ref;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof(int) * X * N);

    cin >> n;
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            cin >> arr[i][j];
        }
    }

    cout << getDp((1 << n) - 1, n - 1) << '\n';
    
    return 0;
}