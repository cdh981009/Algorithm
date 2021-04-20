// 10167: goldmine
// https://www.acmicpc.net/problem/10167
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 3030;
constexpr int X = (1 << 13);

using ll = long long;

int n;
int sn;

struct Point {
    int x, y, v;
} points[N];

using pii = pair<int, int>;
vector<pii> events[N];

ll mn[X];
ll mx[X];
ll nv[X];
ll lazy[X];

void clearTree() {
    memset(mn, 0, sizeof(ll) * X);
    memset(mx, 0, sizeof(ll) * X);
    memset(nv, 0, sizeof(ll) * X);
    memset(lazy, 0, sizeof(ll) * X);
}

void propagate(int node, int l, int r) {
    if (lazy[node] == 0)
        return;

    ll x = lazy[node];
    mn[node] += x;
    mx[node] += x;

    if (l != r) {
        lazy[2 * node] += x;
        lazy[2 * node + 1] += x;
    }

    lazy[node] = 0;
}

void update(int s, int e, int v, int node, int l, int r) {
    propagate(node, l, r);

    if (e < l || r < s) {
        return;
    }

    if (s <= l && r <= e) {
        mn[node] += v;
        mx[node] += v;

        if (l != r) {
            lazy[2 * node] += v;
            lazy[2 * node + 1] += v;
        }
        return;
    }

    int mid = (l + r) / 2;
    update(s, e, v, 2 * node, l, mid);
    update(s, e, v, 2 * node + 1, mid + 1, r);

    mx[node] = max(mx[2 * node], mx[2 * node + 1]);
    mn[node] = min(mn[2 * node], mn[2 * node + 1]);

    nv[node] = max(nv[2 * node], nv[2 * node + 1]);
    nv[node] = max(nv[node], mx[2 * node + 1] - mn[2 * node]);
}

void update(int s, int e, int v) {
    update(s, e, v, 1, 0, sn - 1);
}

ll query(int s, int e, int node, int l, int r) {
    propagate(node, l, r);

    if (e < l || r < s) {
        return 0;
    }

    if (s <= l && r <= e) {
        return nv[node];
    }

    int mid = (l + r) / 2;
    return max(nv[node],
                    max(query(s, e, 2 * node, l, mid), 
                        query(s, e, 2 * node + 1, mid + 1, r)));
}

ll query(int s, int e) {
    return query(s, e, 1, 0, sn - 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    vector<int> px, py;
    px.reserve(n);
    py.reserve(n);

    FOR(i, 0, n) {
        auto& m = points[i];
        cin >> m.x >> m.y >> m.v;
        px.push_back(m.x);
        py.push_back(m.y);
    }

    sort(px.begin(), px.end());
    sort(py.begin(), py.end());
    auto ux = unique(px.begin(), px.end());
    auto uy = unique(py.begin(), py.end());

    FOR(i, 0, n) {
        auto& p = points[i];
        p.x = lower_bound(px.begin(), ux, p.x) - px.begin();
        p.y = lower_bound(py.begin(), uy, p.y) - py.begin() + 1;
        events[p.x].push_back({p.y, p.v});
    }

    int nx = ux - px.begin();
    int ny = uy - py.begin() + 1;

    sn = 1;
    while (sn < ny)
        sn <<= 1;

    ll ans = 0;

    FOR(i, 0, nx) {
        clearTree();

        for (int j = i; j >= 0; --j) {
            for (auto& p : events[j]) {
                update(p.first, sn - 1, p.second);
            }

            ans = max(ans, query(0, ny - 1));
        }
    }

    cout << ans << '\n';

    return 0;
}