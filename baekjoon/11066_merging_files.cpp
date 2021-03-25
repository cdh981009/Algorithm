#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int merge(vector<int>& cost, vector<int>& ps, vector<vector<int>>& dp, int begin, int end) {
    if (begin == end)
        return 0;
    else if (dp[begin][end] != -1)
        return dp[begin][end];
    else {
        int minCost = INF;
        int myCost = ps[end] - (begin == 0 ? 0 : ps[begin - 1]);
        //cout << " " << begin << " " << end << " " << "mySCost " << myCost << endl;
        for (int i = begin; i < end; ++i) {
            minCost = min(minCost, merge(cost, ps, dp, begin, i) + merge(cost, ps, dp, i + 1, end) + myCost);
        }
        //cout << begin << " " << end << " " << minCost << endl;
        return dp[begin][end] = minCost;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        vector<int> cost(n);
        vector<int> ps(n);
        vector<vector<int>> dp(n, vector<int>(n, -1));
        FOR(i, 0, n) {
            int x; cin >> x;
            cost[i] = x;
            ps[i] = (i == 0 ? 0 : ps[i - 1]) + x;
        }
        cout << merge(cost, ps, dp, 0, n - 1) << endl;
    }

    return 0;
}