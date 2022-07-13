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

constexpr int N = 100;
constexpr int M = 1e9 + 7;

int adj[N][N];
int itm[N];
int n, m, r;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> r;
    rep(i, 0, n) cin >> itm[i];
    rep(i, 0, n) rep(j, 0, n) adj[i][j] = i == j ? 0 : INF;
    rep(i, 0, r) {
        int a, b, l;
        cin >> a >> b >> l;
        a--, b--;
        adj[a][b] = adj[b][a] = l;
    }

    rep(k, 0, n) rep(i, 0, n) rep(j, 0, n)
        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

    int ans = 0;
    rep(i, 0, n) {
        int res = 0;
        rep(j, 0, n)
            if (adj[i][j] <= m) res += itm[j];
        ans = max(ans, res);
    }

    cout << ans << '\n';
    return 0;
}