#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 10)
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep_(i, a, b) for (int i = (a); i <= (b); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pii>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 201010;
constexpr int M = 100;

ll n, m, ans;
vi a, b;
bool dp[N][2];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    a = vi(n);
    b = vi(n);

    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];

    dp[n-1][0] = dp[n-1][1] = true;

    for (int i = n - 2; i >= 0; --i) {
        dp[i][0] = false;
        if (dp[i+1][0] && abs(a[i] - a[i+1]) <= m) dp[i][0] = true;
        if (dp[i+1][1] && abs(a[i] - b[i+1]) <= m) dp[i][0] = true;

        dp[i][1] = false;
        if (dp[i+1][0] && abs(b[i] - a[i+1]) <= m) dp[i][1] = true;
        if (dp[i+1][1] && abs(b[i] - b[i+1]) <= m) dp[i][1] = true;
    }

    cout << ((dp[0][0] || dp[0][1]) ? "Yes" : "No") << '\n';


    return 0;
}