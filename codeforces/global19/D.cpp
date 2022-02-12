#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 111;

int n;
ll a[N], b[N], c[N];
ll dp[N][N * N];

ll getDp(int x, ll aSum) {
    if (x >= n) return 0;

    ll& ref = dp[x][aSum];
    if (ref != -1) return ref;
    ref = INT64_MAX;

    // choose not to swap
    ll bSum = (x > 0 ? c[x - 1] : 0) - aSum;
    ref = getDp(x + 1, aSum + a[x]) + 
        (2LL * a[x] * aSum) + (2LL * b[x] * bSum);
        
    // choose to swap
    ref = min(ref, 
          getDp(x + 1, aSum + b[x]) +
        (2LL * b[x] * aSum) + (2LL * a[x] * bSum)
    );

    ref += ((n - 1) * a[x] * a[x]) + ((n - 1) * b[x] * b[x]);



    return ref;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {

        memset(dp, -1,sizeof(dp));
        cin >> n;
        FOR(i, 0, n) cin >> a[i];
        FOR(i, 0, n) cin >> b[i];
        c[0] = a[0] + b[0];
        FOR(i, 1, n) c[i] = c[i - 1] + a[i] + b[i];
        
        cout << getDp(0, 0) << '\n';
    }
    return 0;
}