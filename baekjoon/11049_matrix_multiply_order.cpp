#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 500;
int n;
vector<pair<int, int>> mat(N);
int dp[500][500];

int multiply(int begin, int end) {
    if (begin == end)
        return 0;

    int& ref = dp[begin][end];
    if (ref != -1)
        return ref;
    
    int minCost = INT32_MAX;
    for (int i = begin; i < end; ++ i) {
        minCost = min(minCost, multiply(begin, i) + multiply(i + 1, end) + mat[begin].first * mat[i].second * mat[end].second);
    }

    return ref = minCost;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof(int) * 500 * 500);

    cin >> n;
    FOR(i, 0, n) {
        int a, b; cin >> a >> b;
        mat[i] = {a, b};
    }
    cout << multiply(0, n - 1) << endl;


    return 0;
}