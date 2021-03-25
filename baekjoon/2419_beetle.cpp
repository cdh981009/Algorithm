// 2419: Beetle
// https://www.acmicpc.net/problem/2419
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 301;

int n, m;
int arr[N];
int dp[N][N][2][N];
bool memoi[N][N][2][N];

int z;
int ans = 0;

int getDp(int s, int e, int dir, int remain) {
    if (remain == 0)
        return 0;

    bool& mem = memoi[s][e][dir][remain];
    int& ref = dp[s][e][dir][remain];
    if (mem)
        return ref;
    mem = true;
    ref = -INF;

    // 왼쪽으로 확장
    if (s - 1 >= 0)
        ref = max(ref, m - remain * ((dir == 0 ? arr[s] : arr[e]) - arr[s - 1])
                        + getDp(s - 1, e, 0, remain - 1));

    // 오른쪽으로 확장
    if (e + 1 < n)
        ref = max(ref, m - remain * (arr[e + 1] - (dir == 0 ? arr[s] : arr[e]))
                        + getDp(s, e + 1, 1, remain - 1));

    return ref;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    bool eat = false;
    FOR(i, 0, n) {
        cin >> arr[i];
        if (arr[i] == 0)
            eat = true;
        if (arr[i] < 0)
            z++;
    }
    if (!eat)
        ++n;
    sort(arr, arr + n);

    FOR(i, 1, n) {
        ans = max(ans, getDp(z, z, 0, i));
    }

    cout << ans + (eat ? m : 0) << '\n';

    return 0;
}