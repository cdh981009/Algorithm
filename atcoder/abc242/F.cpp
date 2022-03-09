#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pii>;

constexpr int N = 3000;
constexpr int M = 998244353;

int n, m, b, w;

ll cmb[N][N];
ll dp[N][N][2];

ll comb(int n, int r) {
    if (n == r || r == 0) return 1;
    if (r > n || r < 0) return 0;
    if (r > n / 2) r = n - r;

    ll& ref = cmb[n][r];
    if (ref != -1) return ref;
    return ref = (comb(n - 1, r) + comb(n - 1, r - 1)) % M;
}

ll f(ll n, ll m, bool black) {
    ll x = black ? b : w;
    if (x > n * m) return 0;

    ll& ref = dp[n][m][black];
    if (ref != -1) return ref;
    ref = comb(n * m, x);

    FOR_(i, 1, n) {
        FOR_(j, 1, m) {
            if (i == n && j == m) continue;
            ll base = comb(n, i) * comb(m, j) % M * f(i, j, black) % M;
            ref = (M + ref - base) % M;
        }
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

    cin >> n >> m >> b >> w;
    memset(cmb, -1, sizeof(cmb));
    memset(dp, -1, sizeof(dp));

    ll ans = 0;
    FOR_(i, 1, n) {
        FOR_(j, 1, m) {
            FOR_(k, 1, n - i) {
                FOR_(l, 1, m - j) {
                    ll base = comb(n, i) * comb(m, j) % M * comb(n - i, k) % M * comb(m - j, l) % M * f(i, j, 0) % M * f(k, l, 1) % M;
                    ans = (ans + base) % M;
                }
            }
        }
    }

    cout << ans << '\n';
    
    return 0;
}