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

constexpr int N = 3010101;

int fibs[31] = {
    1,
    2, 3, 5, 8,13,
    21, 34, 55, 89, 144,
    233, 377, 610, 987, 1597,
    2584, 4181, 6765, 10946, 17711,
    28657, 46368, 75025, 121393, 196418,
    317811, 514229, 832040, 1346269, 2178309
};

int dp[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    dp[0] = 0;
    rep(i, 1, N) {
        ll b = 0;
        rep(j, 0, 31) {
            ll x = i - fibs[j];
            if (x < 0) break;
            b |= (1 << dp[x]);
        }
        rep(j, 0, 31) {
            if ((b >> j) & 1) continue;
            dp[i] = j;
            break;
        }
    }

    ll n, s;
    s = 0;
    cin >> n;
    rep(i, 0, n) {
        ll x; cin >> x;
        //cout << dp[x] << '\n';
        s ^= dp[x];
    }

    if (s == 0)
        cout << "cubelover\n";
    else
        cout << "koosaga\n";

    return 0;
}