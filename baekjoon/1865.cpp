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

constexpr int N = 1030;
constexpr int M = 100;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll tc; cin >> tc;
    while (tc--) {
        int n, m, w; cin >> n >> m >> w;
        vector<vector<int>> adj(n, vector<int>(n, INF));
        rep(i, 0, n) adj[i][i] = 0;

        rep(i, 0, m) {
            int s, e, t;
            cin >> s >> e >> t;
            s--, e--;
            adj[s][e] = min(adj[s][e], t);
            adj[e][s] = min(adj[e][s], t);
        }
        rep(i, 0, w) {
            int s, e, t;
            cin >> s >> e >> t;
            s--, e--;
            adj[s][e] = min(adj[s][e], -t);
        }

        rep(k, 0, n) {
            rep(i, 0, n) {
                rep(j, 0, n) {
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }

        bool pos = false;
        rep(i, 0, n) {
            if (adj[i][i] < 0)
                pos = true;
        }
        printYN(pos);
    }

    return 0;
}