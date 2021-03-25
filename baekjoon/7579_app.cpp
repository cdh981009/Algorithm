#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<int> mem(n);
    vector<int> cost(n);
    vector<int> dp(10001, 0);

    FOR(i, 0, n) {
        int x; cin >> x;
        mem[i] = x;
    }
    FOR(i, 0, n) {
        int x; cin >> x;
        cost[i] = x;
    }

    dp[cost[0]] = mem[0];
    for (int i = 1; i < n; ++i) {
        for (int c = 10000; c >= 0; --c) {
            if (c - cost[i] >= 0) 
                dp[c] = max(dp[c - cost[i]] + mem[i], dp[c]);
        }   
    }
    for (int c = 0; c <= 10000; ++c) {
        if (dp[c] >= m) {
            cout << c << "\n";
            break;
        }
    }
    /*
    dp[i][c] : i번 까지 코스트 c를 써서 확보할 수 있는 최대 메모리
    dp[i][c] = max(dp[i - 1][c - cost[i]] + mem[i]
                   dp[i - 1][c])
    */
    return 0;
}