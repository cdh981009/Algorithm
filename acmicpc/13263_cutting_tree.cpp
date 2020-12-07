// 13263: 나무 자르기
// https://www.acmicpc.net/problem/13263
#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 5)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

// convex hull trick
// linear query: time complexity is O(n)
int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    constexpr int N = 1e5 + 5;
    int n;
    cin >> n;
    int a[N];
    int b[N];
    long long dp[N];
    long long sum = 0;
    FOR(i, 0, n) {
        int x;
        cin >> x;
        a[i] = x;
        sum += x;
    }
    sum--;
    FOR(i, 0, n) {
        int x;
        cin >> x;
        b[i] = x;
    }

    int m = b[n - 1];

    FOR(i, 0, n) {
        b[i] -= m;
    }

    dp[0] = 0;
    int stack[N];
    int top = 0;
    stack[0] = 0;
    int queryInd = 0;

    auto crossX = [&](int i, int j) {
        return (double)(dp[stack[j]] - dp[stack[i]]) / (b[stack[i]] - b[stack[j]]);
    };

    FOR(i, 1, n) {
        // calculate dp[i]
        while (queryInd + 1 <= top && crossX(queryInd, queryInd + 1) <= a[i]) {
            queryInd++;
        }
        dp[i] = (long long) a[i] * b[stack[queryInd]] + dp[stack[queryInd]];
        // push new line
        stack[++top] = i;
        while (top >= 2 && crossX(top, top - 1) <= crossX(top - 1, top - 2)) {
            stack[top - 1] = stack[top];
            top--;
        }
    }

    cout << dp[n - 1] + sum * m << '\n';

    return 0;
}