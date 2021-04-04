// 17429: 국제 메시 기구
// https://www.acmicpc.net/problem/17429
#include <bits/stdc++.h>

using namespace std;

#define INF 1987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ull = unsigned long long;

const int N = 501010;
const int X = (1 << 20);
const ull M = (1LL << 32LL);

// heavy light decomposition
// lazy segment tree
int n, q;

vector<int> edge[N];
int depth[N];
int subtree[N];
int parent[N];

int chainHead[N];
int segIndex[N];
int subIndex[N];

int cnt = 0;

int sn;
ull seg[X];
pair<ull, ull> lazy[X];

void initSeg() {
    sn = 1;
    while (sn < n)
        sn <<= 1;
    FOR(i, 1, 2 * sn) {
        lazy[i] = {1, 0};
    }
}

void dfs(int node) {
    subtree[node] = 1;
    for (auto child : edge[node]) {
        if (child == parent[node])
            continue;
        parent[child] = node;
        depth[child] = depth[node] + 1;
        dfs(child);
        subtree[node] += subtree[child];
    }
}

void hld(int node) {
    segIndex[node] = cnt++;

    int heavy = -1;
    int maxSub = 0;
    for (auto child : edge[node]) {
        if (child == parent[node])
            continue;
        if (maxSub < subtree[child]) {
            maxSub = subtree[child];
            heavy = child;
        }
    }

    if (heavy != -1) {
        chainHead[heavy] = chainHead[node];
        hld(heavy);
    }

    for (auto child : edge[node]) {
        if (child == parent[node] || child == heavy)
            continue;
        chainHead[child] = child;
        hld(child);
    }

    subIndex[node] = cnt - 1;
}

void pLazy(int node, const pair<ull, ull>& l) {
    ull u = l.first;
    ull w = l.second;
    lazy[node].first *= u;
    lazy[node].first %= M;

    lazy[node].second *= u;
    lazy[node].second %= M;
    lazy[node].second += w;
    lazy[node].second %= M;
}

void propagate(int node, int nodeL, int nodeR) {
    if (nodeL != nodeR) {
        pLazy(2 * node, lazy[node]);
        pLazy(2 * node + 1, lazy[node]);
    }

    ull span = nodeR - nodeL + 1;
    seg[node] *= lazy[node].first;
    seg[node] %= M;
    seg[node] += span * lazy[node].second;
    seg[node] %= M;

    lazy[node] = {1, 0};
}

void update(int l, int r, int node, int nodeL, int nodeR, int mul, int add) {
    propagate(node, nodeL, nodeR);

    if (r < nodeL || nodeR < l) {
        return;
    } else if (l <= nodeL && nodeR <= r) {
        ull span = nodeR - nodeL + 1;
        seg[node] *= mul;
        seg[node] %= M;
        seg[node] += span * add;
        seg[node] %= M;

        if (nodeR != nodeL) {
            pLazy(2 * node, {mul, add});
            pLazy(2 * node + 1, {mul, add});
        }
    } else {
        int mid = (nodeL + nodeR) / 2;
        update(l, r, 2 * node, nodeL, mid, mul, add);
        update(l, r, 2 * node + 1, mid + 1, nodeR, mul, add);

        seg[node] = seg[2 * node] + seg[2 * node + 1];
        seg[node] %= M;
    }
}

void update(int x, int y, int mul, int add) {
    update(x, y, 1, 0, sn - 1, mul, add);
}

ull query(int l, int r, int node, int nodeL, int nodeR) {
    propagate(node, nodeL, nodeR);

    if (r < nodeL || nodeR < l) {
        return 0;
    } else if (l <= nodeL && nodeR <= r) {
        return seg[node];
    } else {
        int mid = (nodeL + nodeR) / 2;
        ull res =
            query(l, r, 2 * node, nodeL, mid)
          + query(l, r, 2 * node + 1, mid + 1, nodeR);
        return res % M;
    }
}

ull query(int x, int y) {
    return query(x, y, 1, 0, sn - 1);
}

void pathUpdate(int x, int y, int mul, int add) {
    while (chainHead[x] != chainHead[y]) {
        int xx = chainHead[x];
        int yy = chainHead[y];
        if (depth[xx] < depth[yy]) {
            swap(x, y);
            swap(xx, yy);
        }
        update(segIndex[xx], segIndex[x], mul, add);
        x = parent[xx];
    }
    if (depth[x] > depth[y])
        swap(x, y);
    update(segIndex[x], segIndex[y], mul, add);
}

ull pathQuery(int x, int y) {
    ull sum = 0;
    while (chainHead[x] != chainHead[y]) {
        int xx = chainHead[x];
        int yy = chainHead[y];
        if (depth[xx] < depth[yy]) {
            swap(x, y);
            swap(xx, yy);
        }
        sum += query(segIndex[xx], segIndex[x]);
        sum %= M;
        x = parent[xx];
    }
    if (depth[x] > depth[y])
        swap(x, y);
    sum += query(segIndex[x], segIndex[y]);
    sum %= M;

    return sum;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    FOR(i, 0, n - 1) {
        int s, e;
        cin >> s >> e;
        s--;
        e--;
        edge[s].push_back(e);
        edge[e].push_back(s);
    }

    initSeg();
    dfs(0);
    hld(0);

    FOR(i, 0, q) {
        int t, x, y, v;
        cin >> t;
        if (t == 1) {
            // add v to x and it's subtree
            cin >> x >> v;
            x--;
            update(segIndex[x], subIndex[x], 1, v);
        } else if (t == 2) {
            // add v to path from x to y
            cin >> x >> y >> v;
            x--; y--;
            pathUpdate(x, y, 1, v);
        } else if (t == 3) {
            // multiply by v to x and it's subtree
            cin >> x >> v;
            x--;
            update(segIndex[x], subIndex[x], v, 0);
        } else if (t == 4) {
            // multiply by v to path from x to y
            cin >> x >> y >> v;
            x--; y--;
            pathUpdate(x, y, v, 0);
        } else if (t == 5) {
            // print sum of x and it's sumtree
            cin >> x;
            x--;
            cout << query(segIndex[x], subIndex[x]) << '\n';
        } else if (t == 6) {
            // print sum of path from x to y
            cin >> x >> y;
            x--; y--;
            cout << pathQuery(x, y) << '\n';
        }

        // FOR(i, 0, n) {
        //     cout << query(segIndex[i], segIndex[i]) << ' ';
        // }
        // cout << endl;
    }

    
    return 0;
}