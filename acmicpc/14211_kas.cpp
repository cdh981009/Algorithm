// 14211: KAS
// https://www.acmicpc.net/problem/14211
#include <bits/stdc++.h>

using namespace std;

#define INF 1e6
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 500;
constexpr int M = 100001;

int n;
int sum;

int arr[N];
int dp[M];
int aux[M];

// dp[i][diff]: 현재 배분된 돈의 차이가 diff 일 때
// i번째 돈을 배분해서 (안가져가는 선택지도 있음) 
// 마지막엔 차이가 0일 때 최대로 돈을 가져간 값
int solve() {
    // init
    // aux[0] = 0;
    FOR(i, 1, M) {
        aux[i] = -INF;
    }

    FOR(i, 0, n) {
        // dp[i][diff] -> dp[diff] memory compression
        // dp[i + 1][diff] -> aux[diff]
        FOR(j, 0, M) {
            dp[j] = aux[j];
            if (j + arr[i] < M)
                dp[j] = max(dp[j], aux[j + arr[i]] + arr[i]);
            if (j - arr[i] >= 0)
                dp[j] = max(dp[j], aux[j - arr[i]]);
            else
                dp[j] = max(dp[j], aux[arr[i] - j] + arr[i] - j);
        }
        swap(dp, aux);
    }

    return sum - aux[0];
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 0, n) {
        cin >> arr[i];
        sum += arr[i];
    }

    cout << solve() << '\n';

    return 0;
}