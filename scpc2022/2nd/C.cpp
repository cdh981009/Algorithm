#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 7)
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep_(i, a, b) for (int i = (a); i <= (b); ++i)
#define repr_(i, a, b) for (int i = (a); i >= (b); --i)
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

constexpr int N = 101010;
constexpr int M = 8e6 + 10;

int n, m, k, ans;

vector<vector<pii>> edges;
vector<vector<pii>> bedges;

int color[N][4][4];
int dp[N][4][4];

void doScc() {
    vector<int> sccOf(n);
    vector<bool> vst(n, false);
    vector<int> stk;
    int cnt = 0;
    int sum = 0;

    auto dfs1 = [&](auto&& self, int node) -> void {
        vst[node] = true;
        for (auto &[nxt, c] : edges[node]) {
            if (!vst[nxt])
                self(self, nxt);
        }
        stk.push_back(node);
    };

    auto dfs2 = [&](auto&& self, int node) -> void {
        vst[node] = true;
        sccOf[node] = cnt;
        for (auto &[nxt, c] : bedges[node]) {
            if (!vst[nxt])
                self(self, nxt);
            if (sccOf[nxt] == cnt)
                sum |= (1 << c);
        }
    };

    rep(i, 0, n) 
        if (!vst[i]) dfs1(dfs1, i);

    vst = vector<bool>(n, false);

    while (!stk.empty()) {
        int cur = stk.back();
        stk.pop_back();

        if (!vst[cur]) {
            sum = 0;
            cnt++;
            dfs2(dfs2, cur);

            if (sum == 7) {
                ans = INF;
                break;
            }
        }
    }
}

int dfs(int node, int prv, int k) {
    int &col = color[node][prv][k];
    int &ref = dp[node][prv][k];
    
    if (col == 1) return ref;
    if (col == -1) return INF;

    int nxtc = (prv + 1) % 3;

    col = -1;
    ref = 0;

    for (auto &[nxt, c] : edges[node]) {
        if (c == nxtc) { // choose
            int res = dfs(nxt, c, k);

            if (res == INF && k == 3)
                res = 0;

            ref = max(ref, min((int)INF, 1 + res));
        } else { // skip
            if (k == 3) {
                int res = dfs(nxt, prv, k);
                if (res == INF) res = 0;
                ref = max(ref, res);
            } else if (k > 0) {
                int res = dfs(nxt, prv, k - 1);
                ref = max(ref, res);
            }
        }
    }

    col = 1;

    return ref;
}

void doDp() {
    ans = 0;
    rep(i, 0, n)
        rep(j, 0, 3)
            ans = max(ans, dfs(i, j, k));
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    rep(tc, 0, T) {
        cout << "Case #" << tc + 1 << '\n';

        memset(color, 0, sizeof(color));

        cin >> n >> m >> k;
        edges = vector<vector<pii>>(n);
        bedges = vector<vector<pii>>(n);
        rep(i, 0, m) {
            int u, v;
            char c;
            cin >> u >> v >> c;
            u--, v--;
            c -= 'A';
            edges[u].push_back({v, c});
            bedges[v].push_back({u, c});
        }

        ans = 0;

        if (k == -1) {
            doScc();
            k = 3;
        }

        if (ans != INF) {
            doDp();
        }

        if (ans == INF) ans = -1;

        cout << ans << '\n';
    }

    return 0;
}