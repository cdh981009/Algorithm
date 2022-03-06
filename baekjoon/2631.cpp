#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define fi first
#define se second
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (ll i = (a); i <= (b); ++i)

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

constexpr int N = 200;
constexpr int M = 998244353;

int n;
int a[N];
int dp[N];

int getDp(int ind) {
    if (ind == n) return 0;

    int& ref = dp[ind];
    if (ref != -1) return ref;
    ref = 1;

    FOR(i, ind + 1, n) {
        if (a[i] > a[ind])
            ref = max(ref, 1 + getDp(i));
    }

    return ref;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));

    int ans = 0;
    cin >> n;
    FOR(i, 0, n) cin >> a[i];
    
    FOR(i, 0, n) {
        ans = max(ans, getDp(i));
    }

    ans = n - ans;
    cout << ans << '\n';

    return 0;
}