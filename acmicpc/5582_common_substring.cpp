// 5582: 공통 부분 문자열
// https://www.acmicpc.net/problem/5582
#include <bits/stdc++.h>

using namespace std;

#define INF (4e6 + 1)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 4000;

int dp[N][N];

int mx = -1;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    string s, t;
    cin >> s >> t;
    n = s.size();
    m = t.size();

    FOR(i, 0, n) {
        dp[i][0] = (s[i] == t[0]);
        mx = max(mx, dp[i][0]);
    }

    FOR(i, 0, m) {
        dp[0][i] = (s[0] == t[i]);
        mx = max(mx, dp[0][i]);
    }

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            dp[i][j] = (s[i] == t[j]) ? dp[i - 1][j - 1] + 1 : 0;
            mx = max(mx, dp[i][j]);
        }
    }

    cout << mx << '\n';

    return 0;
}