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

constexpr int N = 5010;
constexpr int M = 100;

ll n, m, ans;
string s, t;
ll dp[N][N];

ll getDp(int x, int y) {
    if (x >= n || y >= m) return 0;

    auto& ref = dp[x][y];
    if (ref != -1) return ref;
    if (s[x] != t[y]) return ref = 0;
    else return ref = 1 + getDp(x+1,y+1);
}

void solve() {
    int j = m-1;
    vector<int> suf(n, 0);
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == t[j]) j--;
        suf[i] = j + 1;
    }

    j = 0;
    vector<int> pre(n, 0);
    rep(i, 0, n) {
        if (s[i] == t[j]) j++;
        pre[i] = j - 1;
    }

    rep(i, 0, n) {
        rep(j, 0, m) {
            if (suf[i] > j) continue;
            if (i - 1 >= 0) {
                if (pre[i - 1] < j - 1) continue;
            } else // i == 0
                if (j != 0) continue;
            
            ll res = n - i - getDp(i, j);
            if (i != 0) {
                res++;
                res += 2 * i - j;
            }
            ans = min(ans, res);
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        cin >> s >> t;
        int j = 0;
        bool pos = false;

        rep(i, 0, n) {
            if (s[i] == t[j]) {
                j++;
                if (j == m) {
                    pos = true;
                    break;
                }
            }
        }

        if (!pos)
            cout << -1 << '\n';
        else {
            rep(i, 0, n) rep(j, 0, m) dp[i][j] = -1;
            ans = INF;
            solve();
            cout << ans << '\n';
        }
    }

    return 0;
}