// 13261: 탈옥
// https://www.acmicpc.net/problem/13261
#include <bits/stdc++.h>

using namespace std;

#define INF INT64_MAX
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 8001;
constexpr int G = 801;
int n, g;
long long c[N];
long long dp[N][G];

/*
// dp[i][j]: i번째 칸까지 j개로 나누었을 때 위험도의 최소값
// 답: dp[n][g]
//
// base: dp[i][1] = sum(i) * i
// dp[i][j] = min(dp[k][j - 1] + (sum(i) - sum(k)) * (i - k)) for all (1 <= k < i)
// dp[i][j]를 결정하는 k값의 최솟값을 opt(i, j)라고 하자
// dp[k][j - 1] + (sum(i) - sum(k)) * (i - k) < dp[k - x][j - 1] + (sum(i) - sum(k - x)) * (i - k + x)
// => dp[k][j - 1] - sum(k) * (i - k) < dp[k - x][j - 1] + sum(i) * x - sum(k - x) * (i - k + x) .. (1)
//
// 그러면 dp[i + 1][j]를 고려할 때 k = opt(i, j)라 하자
// dp[k][j - 1] + (sum(i + 1) - sum(k)) * (i + 1 - k) 와
// dp[k - x][j - 1] + (sum(i + 1) - sum(k - x)) * (i + 1 - k + x) 를 비교하는 것은 (1)에 의해
//
// dp[k][j - 1] - sum(k) * (i + 1 - k) < dp[k - x][j - 1] + sum(i + 1) * x - sum(k - x) * (i + 1 - k)
//                 ^sum(k) 만큼 작아짐                        ^커짐            ^sum(k - x) 만큼 작아짐
// (sum(k) > sum(k - x))
//
// 따라서 opt(i, j) <= opt(i + 1, j) 이므로 분할정복 트릭 사용가능
*/

// dp[s][x] 부터 ans[e][x] 까지 값을 구하고 값의 후보를 p부터 q까지만 확인한다
void work(int s, int e, int x, int p, int q) {
    int mid = (s + e) / 2;

    long long& ref = dp[mid][x];
    ref = INF;
    int opt = 0;

    FOR_(k, p, min(q, mid - 1)) {
        long long res = dp[k][x - 1] + (long long)(mid - k) * (c[mid] - c[k]);
        if (res < ref) {
            ref = res;
            opt = k;
        }
    }

    if (s <= mid - 1)
        work(s, mid - 1, x, p, opt);
    if (mid + 1 <= e)
        work(mid + 1, e, x, opt, q);
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> g;
    FOR_(i, 1, n) {
        int x;
        cin >> x;
        c[i] = c[i - 1] + x;
        dp[i][1] = (long long)c[i] * i;
    }

    g = min(g, n);
    FOR_(x, 2, g)
        work(x, n, x, x - 1, n);

    cout << dp[n][g] << '\n';

    return 0;
}