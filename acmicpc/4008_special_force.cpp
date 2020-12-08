// 4008: 특공대
// https://www.acmicpc.net/problem/4008
#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 5)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

/*
    // f(x) = a * x^2 + b * x + c
    // dp[i] = max(dp[j] + f(sum(j + 1 ... i))) (j < i)
    // 
    //   dp[j] + f(sum(j + 1 ... i))
    // = dp[j] + f(sum[i] - sum[j])
    // = dp[j] + a * (x - y)^2 + b * (x - y) + c
    // = dp[j] + f(x) + f(-y) - 2a * x * y - c
    //
    // => dp[i] - f(sum[x]) + c = max(dp[j] + f(-sum[j]) - 2a * sum[i] * sum[j])
*/

constexpr int N = 1e6 + 1; // 1e5;

int n;
int a, b, c;
int sum[N];

inline long long f(long long x) {
    return x * x * a + x * b + c;
};

struct Line {
    long long a;
    long long b;

    Line() {}
    Line(long long _dp, long long prefixSum) {
        a = -2 * ::a * prefixSum;
        b = _dp + f(-prefixSum);
    }
} stk[N];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> a >> b >> c;
    
    sum[0] = 0;
    FOR(i, 0, n) {
        int x; cin >> x;
        sum[i + 1] = x + sum[i];
    }

    int top = 0;
    int queryInd = 0;
    stk[0] = Line(0, 0);

    auto crossX = [&](int i, int j) {
        return (double)(stk[j].b - stk[i].b) / (stk[i].a - stk[j].a);
    };

    long long dp;
    FOR(i, 1, n + 1) {
        // 1. calculate dp[i]
        while (queryInd + 1 <= top && crossX(queryInd, queryInd + 1) <= sum[i]) {
            queryInd++;
        }

        // => dp[i] - f(sum[x]) + c = max(dp[j] + f(-sum[j]) + (-2a * sum[j]) * sum[i])
        dp = stk[queryInd].b + stk[queryInd].a * sum[i] + f(sum[i]) - c;

        // 2. push new line
        stk[++top] = Line(dp, sum[i]);
        while (top >= 2 && crossX(top, top - 1) <= crossX(top - 1, top - 2)) {
            stk[top - 1] = stk[top];
            top--;
        }
    }

    cout << dp << '\n';
    
    return 0;
}