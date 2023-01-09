#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 7)
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep_(i, a, b) for (int i = (a); i <= (b); ++i)
#define repr_(i, a, b) for (int i = (a); i >= (b); --i)
#define printYN(pos) cout << (pos ? "YES" : "NO") << '\n'
#define printPOS(pos) cout << (pos ? "POSSIBLE" : "IMPOSSIBLE") << '\n'

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 310;
constexpr int M = 998244353;
constexpr int O = N * N;

ll n, m, k, q, ans;
ll a[N], b[N], dp[N][N * N * 2];

ll getDp(int ind, int diff) {
    if (ind == n - 1) return 1;

    ll& ref = dp[ind][diff + O];
    if (ref != -1) return ref;
    
    ll x = a[ind] + diff;
    if (x == 0) {
        return ref = getDp(ind + 1, 0);
    } else {
        return ref = (getDp(ind + 1, x) + getDp(ind + 1, -x)) % M;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));
    cin >> n;
    rep(i, 0, n) cin >> a[i];

    cout << getDp(1, 0) << '\n';

    return 0;
}