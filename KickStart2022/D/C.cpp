#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
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

constexpr int N = 2530;

int n, m;
int s[N], k[N];
int dp[N][N];
int l[N][N], r[N][N];

int getDp(int si, int ki) {
    if (ki == -1) return INF;
    if (si == n - 1) return 0;

    auto& ref = dp[si][ki];
    if (ref != -1) return ref;
    ref = INF;

    int nxt = s[++si];
    ref = min(ref, getDp(si, l[nxt][ki]) + ki - l[nxt][ki]);
    ref = min(ref, getDp(si, r[nxt][ki]) + r[nxt][ki] - ki);

    return ref;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    for (int testcase = 1; testcase <= tc; ++testcase) {
        cout << "Case #" << testcase << ": ";

        cin >> n;
        rep(i, 0, n) cin >> s[i];
        cin >> m;
        rep(i, 0, m) cin >> k[i];

        memset(l, -1, sizeof(l));
        memset(r, -1, sizeof(r));
        memset(dp, -1, sizeof(dp));

        rep(i, 1, N) {
            rep(j, 0, m) {
                if (k[j] == i) 
                    l[i][j] = j;
                else if (j > 0)
                    l[i][j] = l[i][j-1];

                if (k[m - j - 1] == i)
                    r[i][m - j - 1] = m - j - 1;
                else if (m - j - 1 + 1 < m)
                    r[i][m - j - 1] = r[i][m - j];
            }
        }

        int ans = INF;
        rep(i, 0, m) {
            if (k[i] == s[0]) ans = min(ans, getDp(0, i));
        }
        cout << ans << '\n';
    }

    return 0;
}