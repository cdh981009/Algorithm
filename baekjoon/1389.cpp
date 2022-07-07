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
constexpr int M = 10007;

ll n, m;
int adj[N][N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    rep(i, 0, n) {
        rep(j, 0, n) {
            if (i == j)
                adj[i][i] = 0;
            else
                adj[i][j] = INF;
        }
    }
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    rep(k, 0, n) {
        rep(i, 0, n) {
            rep(j, 0, n) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    ll ans = INF;
    ll ansi = -1;
    rep(i, 0, n) {
        ll res = 0;
        rep(j, 0, n) {
            res += adj[i][j];
        }
        if (ans > res) {
            ans = res;
            ansi = i;
        }
    }

    cout << ansi + 1 << '\n';
    return 0;
}