// 13263: 나무 자르기
// https://www.acmicpc.net/problem/13263
#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 5)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

/*
// 문제:
// 단조 증가하는 수열 a와 단조 감소하는 수열 b가 있다. 이 때 a[0] == 1 (무조건)
// 처음에는 a[0]을 택해 1 -> 0으로 만들어야 한다. 이 때 cost는 없다.
// 그 다음부터 어떤 x를 택해 a[x]를 1 줄일 수 있다. 이 때 cost는 지금까지 a를 0으로 만든 인덱스 i에 대해
// b[i]중 최솟값이다. 다르게 말하면 지금까지 a를 0으로 만든 인덱스 i중 최대값에 대한 b[i]이다.
// 모든 a를 0으로 만들 때 minimum cost를 구하라.
*/

/* 풀이:
// 1)
// 관찰하면
// 어떤 a[x]를 택해 줄이기 시작하면 완전히 줄이지 않을 이유가 없다 (greedy)
// 모든 b[x]가 동일한 수 m 만큼 감소해도 풀이는 변하지 않는다 (답에 sigma(a[1...n - 1]) * m 만큼 더해준다면)
// 따라서 m = b[n - 1]으로 택해 모든 b 를 m 만큼 줄이고 b[n - 1]를 0으로 만든다면,
// 어떻게든 마지막 a를 0으로 만든 후에는 아직 0이 아닌 a를 모두 0으로, cost 없이 바꿀 수 있다.
// 이 때, 어떤 a[x]를 0으로 만들었다면 a[n - 1]를 0으로 만들어 cost를 0으로 줄이기 전까진, y < x인 a[y]를 0으로 만들 이유가 없다 (greedy)
// 이미 cost는 b[x]이므로 b[x] < b[y] 인 b[y]는 도움이 되지 않기 때문이다.
//
// 2)
// 따라서 문제는 x를 1...n-1 까지 증가시키며 a[x]를 0으로 만들지 말지 고르는 것으로 변형된다.
// 
// dp[x]: dp[1...x-1]를 구했다 치자, a[1..x-1]를 각각 0으로 만들었을 수도 있고 아닐 수도 있다.
// 이 때 a[x]를 0으로 만들 때 지금까지의 최소 cost
//
// dp[i] = min(dp[j] + b[j] * a[i]) (모든 j < i에 대해)
//
// 이 때 점화식을 잘 관찰하면 b[j] 가 단조 감소하므로,
// j + 1개의 일차함수 y = b[j] * x + dp[j] 중
// x = a[i] 인 지점에서 최솟값을 구하는 문제가 된다.
// dp[i]를 구하면 새 일차함수를 넣는다
// 나머지는 일반적인 convex hull trick 풀이이다.
*/

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