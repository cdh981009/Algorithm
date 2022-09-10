#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 7)
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep_(i, a, b) for (int i = (a); i <= (b); ++i)
#define repr_(i, a, b) for (int i = (a); i >= (b); --i)
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

constexpr int N = 202020;
constexpr int M = 100;

ll n, m;
vector<pii> edges;
bool red[N];
bool vst[N];
vector<int> adj[N];

vector<int> sz(N + 1);
vector<int> root(N + 1);

int find(int x) {
    if (root[x] == x)
        return x;
    return root[x] = find(root[x]);
}

bool same(int x, int y) {
    return find(x) == find(y);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y)
        return;

    if (sz[x] < sz[y])
        swap(x, y);

    root[y] = x;
    sz[x] += sz[y];
}

int size(int x) {
    return sz[find(x)];
}

void dfs(int curr, int tar, int prv) {
    vst[curr] = true;

    for (auto nxt : adj[curr]) {
        if (prv == nxt) continue;
        if (vst[nxt]) continue;

        if (nxt == tar) {
            rep(i, 0, m) {
                auto &[u, v] = edges[i];
                if ((u == curr && v == tar) ||
                    (u == tar && v == curr)) {
                    red[i] = false;
                    return;
                }
            }
            return;
        }

        dfs(nxt, tar, curr);
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

        edges.clear();
        rep(i, 0, n) {
            root[i] = i;
            sz[i] = 1;
            adj[i].clear();
            vst[i] = false;
        }

        rep(i, 0, m) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            edges.push_back({u, v});
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // build mst
        set<int> blues;
        int bInd;
        rep(i, 0, m) {
            auto &[u, v] = edges[i];
            if (!same(u, v)) {
                unite(u, v);
                red[i] = true;
            } else {
                red[i] = false;
                blues.insert(u);
                blues.insert(v);
                bInd = i;
            }
        }

        if (m - n + 1 == 3 && blues.size() == 3) {
            auto &[u, v] = edges[bInd];
            red[bInd] = true;
            dfs(u, v, v);
        }

        rep(i, 0, m) {
            cout << red[i];
        }

        cout << '\n';
    }

    return 0;
}