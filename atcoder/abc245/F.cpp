#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 10)
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep_(i, a, b) for (int i = (a); i <= (b); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pii>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 201010;
constexpr int M = 100;

ll n, m, ans;
vector<int> edges[N];
vector<int> backEdges[N];
bool visited[N];

int cnt = 0;
vector<int> stk;
vector<vector<int>> scc;
int myScc[N];
bool stat[N];

vector<int> sccEdge[N];

void dfs1(int node) {
    visited[node] = true;
    for (auto child : edges[node]) {
        if (!visited[child])
            dfs1(child);
    }
    stk.push_back(node);
}

void dfs2(int node) {
    visited[node] = true;
    for (auto child : backEdges[node]) {
        if (!visited[child])
            dfs2(child);
    }
    scc.back().push_back(node);
}

bool dfs3(int sccNode) {
    bool& st = stat[sccNode];

    if (visited[sccNode]) return st;
    visited[sccNode] = true;

    st = scc[sccNode].size() > 1;

    auto &v = sccEdge[sccNode];
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for (auto nxt: v) {
        st |= dfs3(nxt);
    }

    if (st) ans += scc[sccNode].size();
    return st;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    rep(i, 0, m) {
        int u, v; cin >> u >> v;
        u--, v--;
        edges[u].push_back(v);
        backEdges[v].push_back(u);
    }

    FOR(i, 0, n) {
        if (!visited[i]) {
            dfs1(i);
        }
    }

    FOR(i, 0, n) {
        visited[i] = false;
    }

    FOR(i, 0, stk.size()) {
        auto node = stk[stk.size() - 1 - i];
        if (!visited[node]) {
            scc.push_back(vector<int>());
            dfs2(node);
            // sort(scc.back().begin(), scc.back().end());
        }
    }

    rep(i, 0, scc.size()) {
        for (auto &node : scc[i]) {
            myScc[node] = i;
        }
    }

    rep(i, 0, scc.size()) {
        for (auto &node : scc[i]) {
            for (auto &adj : edges[node]) {
                if (myScc[adj] != myScc[node]) {
                    sccEdge[i].push_back(myScc[adj]);
                }
            }
        }
    }

    rep(i, 0, scc.size())
        visited[i] = false;
    
    rep(i, 0, scc.size()) {
        if (!visited[i]) dfs3(i);
    }

    cout << ans << '\n';

    return 0;
}