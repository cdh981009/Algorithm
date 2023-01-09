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

constexpr int N = 1010101;
constexpr int M = 100;

ll a, b, c, k;
ll dp[N][4];

ll getDp(ll k, ll dir = 0) {
    dir = (dir + 4) % 4;
    if (k == 0) return dir == 0 ? 0 : INF;
    if (k < 0) return INF;

    ll& ref = dp[k][dir];

    if (ref != -1) return ref;

    ref = INF;

    ref = min(ref, 1 + getDp(k - a, dir - 1));
    ref = min(ref, 1 + getDp(k - b, dir + 1));
    ref = min(ref, 1 + getDp(k - c, dir + 2));


    return ref;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    memset(dp, -1, sizeof(dp));

    cin >> a >> b >> c >> k;

    ll ans = getDp(k, 0);
    if (ans > N) ans = -1;
    cout << ans << '\n';

    return 0;
}