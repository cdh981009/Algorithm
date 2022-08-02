#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 7)
#define fi first
#define se second
#define rep(i, a, b) for (ll i = (a); i < (b); ++i)
#define rep_(i, a, b) for (ll i = (a); i <= (b); ++i)
#define repr_(i, a, b) for (ll i = (a); i >= (b); --i)
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (ll i = (a); i <= (b); ++i)
#define printYN(pos) cout << (pos ? "YES" : "NO") << '\n'
#define printPOS(pos) cout << (pos ? "POSSIBLE" : "IMPOSSIBLE") << '\n'

using ll = long long;
using pii = pair<ll, ll>;
using pll = pair<ll, ll>;
using vi = vector<ll>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using mii = map<ll, ll>;
using mll = map<ll, ll>;

constexpr ll N = 101010;

ll n, m;
ll ans;
ll a[N];
ll dp[N][5][5];

ll getDp(int ind, int x, int y) {
    if (ind == n) return 0;
    if (x != 0 && x == y) return INF;

    auto &ref = dp[ind][x][y];
    if (ref != -1) return ref;

    ref = 0;

    int t = a[ind];
    // use x
    ll rx = getDp(ind + 1, t, y);
    ll ry = getDp(ind + 1, x, t);

    ll ax, ay;

    auto op = [](int x, int t) {
        if (x == 0) return 2;
        if (x == t) return 1;
        if (x + 2 == t || t + 2 == x) return 4;
        return 3;
    };

    ax = op(x, t);
    ay = op(y, t);

    ref = min(ax + rx, ay + ry);
    return ref;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));

    n = 0;
    while (true) {
        ll x; cin >> x;
        if (x == 0) break;
        a[n++] = x;
    }

    cout << getDp(0, 0, 0) << '\n';

    return 0;
}