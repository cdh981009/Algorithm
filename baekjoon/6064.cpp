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

constexpr int N = 1010;
constexpr int M = 10007;

ll n, m, x, y;

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }

    return a;
}
ll solve() {
    x %= m;
    y %= n;
    ll k = m * n / gcd(m, n);
    // cout << k << '\n';
    for (int i = 0; i <= k; i += m) {
        ll j = i + x;
        if (j == 0) continue;
        if (j % n == y) {
            return j;
        }
    }
    return -1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    while (tc--) {
        cin >> m >> n >> x >> y;
        cout << solve() << '\n';
    }

    return 0;
}