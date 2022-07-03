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
constexpr int M = 100;

int n, m, q;

int num[N];
int bit[N][16];
vpii edges;

ll ans = INF;

struct C {
    int t, u, i, v, j;
};

vector<C> constraints;

int cap[N][N];
int cache[N];
int lvl[N];

struct Flow {
    int n;
    vector<vi> edges;

    Flow(int _n) : n(_n) {
        memset(cap, 0, sizeof(cap));
        edges = vector<vi>(n);
    };

    bool init(int src, int snk) {
        memset(lvl, -1, sizeof(lvl));

        queue<int> q;
        q.push(src);
        lvl[src] = 0;

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            if (curr == snk) break;

            rep(i, 0, edges[curr].size()) {
                int nxt = edges[curr][i];
                if (lvl[nxt] == -1 && cap[curr][nxt] > 0) {
                    lvl[nxt] = lvl[curr] + 1;
                    q.push(nxt);
                }
            }
        }

        return lvl[snk] != -1;
    }

    void addEdge(int a, int b, int c, bool bidir = true) {
        cap[a][b] += c;
        if (bidir)
            cap[b][a] += c;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    ll flow(int curr, int sink, int c) {
        if (curr == sink) return c;

        rep(i, cache[curr], edges[curr].size()) {
            cache[curr] = i;
            int nxt = edges[curr][i];
            if (lvl[nxt] == lvl[curr] + 1 && cap[curr][nxt] > 0) {
                ll ret = flow(nxt, sink, min(c, cap[curr][nxt]));
                if (ret > 0) {
                    cap[curr][nxt] -= ret;
                    cap[nxt][curr] += ret;
                    return ret;
                }
            }
        }

        return 0;
    }

    ll maxFlow(int src, int sink) {
        ll res = 0;
        while (init(src, sink)) {
            memset(cache, 0, sizeof(cache));
            while (true) {
                ll f = flow(src, sink, INF);
                res += f;
                if (f == 0) break;
            }
        }

        return res;
    }
};

void solve() {
    ll res = 0;

    rep(b, 0, 16) {
        Flow flow(n + 2);
        int one = n;       // src
        int zero = n + 1;  // sink

        for (auto& [u, v] : edges) {
            auto ub = bit[u][b];
            auto vb = bit[v][b];

            if (ub != -1 && vb != -1) {
                if (ub != vb) res++;
            } else if (ub != -1) {
                if (ub == 1)
                    flow.addEdge(one, v, 1);
                else
                    flow.addEdge(zero, v, 1);
            } else if (vb != -1) {
                if (vb == 1)
                    flow.addEdge(one, u, 1);
                else
                    flow.addEdge(zero, u, 1);
            } else {
                flow.addEdge(u, v, 1);
            }
        }

        res += flow.maxFlow(one, zero);
    }

    ans = min(ans, res);
}

void putConst(int i) {
    if (i == q) {
        solve();
        return;
    }

    auto& c = constraints[i];
    auto& uRef = bit[c.u][c.i];
    auto& vRef = bit[c.v][c.j];

    if (uRef != -1 && vRef != -1) {
        if (c.t == 0 && uRef == vRef) putConst(i + 1);
        if (c.t == 1 && uRef != vRef) putConst(i + 1);
    } else if (uRef != -1) {
        vRef = c.t == 0 ? uRef : 1 - uRef;
        putConst(i + 1);

        vRef = -1;
    } else if (vRef != -1) {
        uRef = c.t == 0 ? vRef : 1 - vRef;
        putConst(i + 1);

        uRef = -1;
    } else {  // both -1
        uRef = 0;
        vRef = c.t == 0 ? uRef : 1 - uRef;
        putConst(i + 1);

        uRef = 1;
        vRef = c.t == 0 ? uRef : 1 - uRef;
        putConst(i + 1);

        uRef = vRef = -1;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    rep(i, 0, n) {
        cin >> num[i];
        if (num[i] == -1) {
            rep(j, 0, 16) bit[i][j] = -1;
        } else {
            rep(j, 0, 16) bit[i][j] = ((num[i] >> j) & 1);
        }
    }
    cin >> q;
    rep(k, 0, q) {
        int t, u, i, v, j;
        cin >> t >> u >> i >> v >> j;
        constraints.push_back({t, u, i, v, j});
    }

    putConst(0);

    if (ans == INF) ans = -1;

    cout << ans << '\n';

    return 0;
}