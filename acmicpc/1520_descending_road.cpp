#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int go(vector<vector<int>>& arr, vector<vector<int>>& dp, int n, int m) {
    if (n == arr.size()-1 && m == arr[0].size()-1)
        return 1;
    int& ref = dp[n][m];
    if (ref != -1) return ref;
    const static vector<pair<int, int>> v {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    ref = 0;
    FOR(i, 0, v.size()) {
        int x = n + v[i].first;
        int y = m + v[i].second;
        if (x >= 0 && x < arr.size() && y >= 0 && y < arr[0].size() && arr[x][y] < arr[n][m])
            ref += go(arr, dp, x, y);
    }
    return ref;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    vector<vector<int>> dp(n, vector<int>(m, -1));
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            int x; cin >> x;
            arr[i][j] = x;
        }
    }
    cout << go(arr, dp, 0, 0) << endl;
    /*
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    */
    return 0;
}