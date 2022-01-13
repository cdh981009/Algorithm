#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using tup = tuple<int, int, int>;

constexpr int N = 5e4;
constexpr int L = 17;
int n, m;
int root[N];
int sz[N];

int find(int x) {
    return root[x] == x ? x : root[x] = find(root[x]);
}

bool same(int x, int y) {
    return find(x) == find(y);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x, y);
    root[y] = x;
    sz[x] += sz[y];
}

int par[N][L];
int depth[N];
pii mw[N][L];

vector<tup> e;
vector<pii> tree[N];
vector<tup> noTree;

void dfs(int node, int p) {
    par[node][0] = p;
    for (auto &[c, w] : tree[node]) {
        if (c == p) continue;
        depth[c] = depth[node] + 1;
        mw[c][0] = {w, -1};
        dfs(c, node);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    FOR(i, 0, N) {
        root[i] = i;
    }

    cin >> n >> m;
    e.resize(m);
    for (auto &[w, s, d] : e) {
        cin >> s >> d >> w;
        s--, d--;
    }
    sort(e.begin(), e.end());

    // 1. get mst
    int cnt = 0, mst = 0;
    for (auto &[w, s, d] : e) {
        if (!same(s, d)) {
            unite(s, d);
            ++cnt, mst += w;
            tree[s].push_back({d, w});
            tree[d].push_back({s, w});
        } else {
            noTree.push_back({w, s, d});
        }
    }
    if (cnt != n - 1) {  // no mst
        cout << -1 << '\n';
        return 0;
    }

    // 2. construct tree
    memset(mw, -1, sizeof(mw));

    dfs(0, 0);

    auto op = [](const pii &x, const pii &y) -> pii {
        if (x.first == y.first) {
            return {x.first, max(x.second, y.second)};
        } else if (x.first > y.first) {
            return {x.first, max(x.second, y.first)};
        } else {
            return {y.first, max(y.second, x.first)};
        }
    };

    FOR(i, 1, L) {
        FOR(j, 0, n) {
            int p = par[j][i - 1];
            par[j][i] = par[p][i - 1];
            mw[j][i] = op(mw[j][i - 1], mw[p][i - 1]);
        }
    }

    // 3. for every non-tree edge, add the edge and delete biggest edge in the cycle
    int ans = INT32_MAX;
    bool pos = false;
    for (auto &[w, x, y] : noTree) {
        pii res = {-1, -1};

        if (depth[x] < depth[y]) swap(x, y);

        for (int i = L - 1; i >= 0; --i) {
            int xx = par[x][i];
            if (depth[xx] >= depth[y]) {
                res = op(res, mw[x][i]);
                x = xx;
            }
        }

        assert(depth[x] == depth[y]);

        if (x != y) {
            for (int i = L - 1; i >= 0; --i) {
                int xx = par[x][i];
                int yy = par[y][i];
                if (xx != yy) {
                    res = op(res, mw[x][i]);
                    res = op(res, mw[y][i]);
                    x = xx;
                    y = yy;
                }
            }

            res = op(res, mw[x][0]);
            res = op(res, mw[y][0]);

            assert(par[x][0] == par[y][0]);
        }

        int mstp = mst;

        if (res.first != w) {
            mstp = mst + w - res.first;
        } else if (res.second != -1) {
            mstp = mst + w - res.second;
        }

        if (mstp != mst)
            pos = true, ans = min(ans, mstp);
    }

    cout << (pos ? ans : -1) << '\n';

    return 0;
}