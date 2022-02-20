#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 100;

int n, x;
vector<int> a, b;
int dp[100][10001];

bool getDp(int i, int p) {
    if (p > x) return false;
    if (i == n) return p == x;

    int &ref = dp[i][p];
    if (ref != -1) return ref;
    return (ref = (getDp(i + 1, p + a[i]) || getDp(i + 1, p + b[i])));
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));

    cin >> n >> x;
    a = vector<int>(n);
    b = vector<int>(n);
    FOR(i, 0, n) {
        cin >> a[i] >> b[i];
    }

    cout << (getDp(0, 0) ? "Yes" : "No") << '\n';
    return 0;
}