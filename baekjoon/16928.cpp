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
constexpr int M = 10007;

int adj[N][N];
bool l[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    rep(i, 0, 100) {
        rep(j, 0, 100) {
            adj[i][j] = i == j ? 0 : INF;
        }
    }
    rep(i, 0, n + m) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u][v] = 0;
        l[u] = true;
    }
    rep(i, 0, 100) {
        if (l[i]) continue;
        rep_(j, 1, 6) {
            if (i + j >= 100) continue;
            adj[i][i + j] = 1;
        }
    }

    rep(k, 0, 100) {
        rep(i, 0, 100) {
            rep(j, 0, 100) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    cout << adj[0][99] << '\n';

    return 0;
}