#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 7)
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep_(i, a, b) for (int i = (a); i <= (b); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)
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

constexpr int N = 61;

map<ll, int> dp[N];

int getDp(int x, ll b) {
    if (x == 0) return 0;

    b &= ((1LL << x) - 1LL);

    if (dp[x].count(b)) return dp[x][b];

    int res = 0;
    ll bb = 0;

    rep_(i, 1, x) {
        ll used = (b & (1LL << (i - 1)));
        if (used) continue;

        int r = getDp(x - i, b | (1LL << (i - 1)));
        bb |= (1 << r);
    }

    rep_(i, 0, 63) {
        if ((bb >> i) & 1) continue;
        res = i;
        break;
    }

    return dp[x][b] = res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k, s;
    cin >> n;
    s = 0;

    rep(i, 0, n) {
        ll x; cin >> x;
        x = getDp(x, 0);
        s ^= x;
    }

    if (s == 0)
        cout << "cubelover\n";
    else
        cout << "koosaga\n";


    return 0;
}