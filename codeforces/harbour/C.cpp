#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 10;

int n;
string s;
int ans;
int dp[10][10][10];

int solve(int a, int b, int i) {
    if (i == 10)
        return i;

    int& ref = dp[a][b][i];
    if (ref != -1)
        return ref;

    if (i >= 1) {
        bool end = false;
        int remA = 4 - ((i - 1) / 2);
        int remB = 5 - (i / 2);

        if (b - a > remA || a - b > remB)
            end = true;

        if (end) {
            ref = i;
            ans = min(ref, ans);
            return ref;
        }
    }

    if (s[i] == '1') {
        i % 2 == 0 ? a++ : b++;
        ref = solve(a, b, i + 1);
    } else if (s[i] == '?') {
        if (i % 2 == 0) {
            ref = min(solve(a, b, i + 1),
                    solve(a + 1, b, i + 1));
        } else {
            ref = min(solve(a, b, i + 1),
                    solve(a, b + 1, i + 1));
        }
    } else {
        ref = solve(a, b, i + 1);
    }

    return ref;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        ans = 10;
        memset(dp, -1, sizeof(int) * 1000);
        cin >> s;
        solve(0, 0, 0);

        cout << ans << '\n';
    }
    return 0;
}