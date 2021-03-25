#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e3;
int dp[N][N];
pair<int, int> bt[N][N];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, 0, sizeof(int) * N * N);
    memset(bt, -1, sizeof(int) * N * N);

    string s1, s2; cin >> s1 >> s2;
    int n, m; n = s1.length(); m = s2.length();
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            if (s1[i] == s2[j]) {
                dp[i][j] = (i == 0 || j == 0 ? 0 : dp[i-1][j-1]) + 1;
                bt[i][j] = {i-1, j-1};
            } else {
                dp[i][j] = (i == 0 ? 0 : dp[i-1][j]);
                bt[i][j] = {i-1, j};
                if (j != 0 && dp[i][j] < dp[i][j-1]) {
                    dp[i][j] = dp[i][j-1];
                    bt[i][j] = {i, j-1};
                }
            }
        }
    }
    int len = dp[n-1][m-1];
    cout << len << "\n";
    if (len > 0) {
        int x = n-1, y = m-1;
        vector<char> ans;
        while (x >= 0 && y >= 0) {
            if (s1[x] == s2[y])
                ans.push_back(s1[x]);
            auto prev = bt[x][y];
            x = prev.first;
            y = prev.second;
        }
        for (auto i = ans.rbegin(); i != ans.rend(); ++i)
            cout << *i;
        cout << "\n";
    }
    return 0;
}