#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 301010;
constexpr int X = (1 << 21);

int n, m;
int ans;
int arr[2 * N];
int prv[N];
int cnt;
int sn;

vector<pii> intervals[N];
pii seg[X];
pii lazy[X];

// max tree
void prpgt(int node, int nodeL, int nodeR) {
    seg[node] = max(seg[node], lazy[node]);

    if (nodeL != nodeR) {
        lazy[2 * node]     = max(lazy[node], lazy[2 * node]);
        lazy[2 * node + 1] = max(lazy[node], lazy[2 * node + 1]);
    }

    lazy[node] = {0, 0};
}

// update x to all elements in range [l, r]
void rangeUpdate(int l, int r, const pii& x, int node, int nodeL, int nodeR) {
    prpgt(node, nodeL, nodeR);

    if (r < nodeL || nodeR < l) {
        return;
    }

    if (l <= nodeL && nodeR <= r) {
        lazy[node] = x;
        prpgt(node, nodeL, nodeR);

        return;
    }

    int mid = (nodeL + nodeR) / 2;
    rangeUpdate(l, r, x, 2 * node, nodeL, mid);
    rangeUpdate(l, r, x, 2 * node + 1, mid + 1, nodeR);

    seg[node] = max(seg[2 * node], seg[2 * node + 1]);
    return;
}

void rangeUpdate(const int l, const int r, const pii& x) {
    rangeUpdate(l, r, x, 1, 0, sn - 1);
}

pii rangeQuery(const int l, const int r, int node, int nodeL, int nodeR) {
    prpgt(node, nodeL, nodeR);

    if (r < nodeL || nodeR < l)
        return {0, 0};

    if (l <= nodeL && nodeR <= r)
        return seg[node];

    int mid = (nodeL + nodeR) / 2;
    return max(rangeQuery(l, r, 2 * node, nodeL, mid),
               rangeQuery(l, r, 2 * node + 1, mid + 1, nodeR));
}

pii rangeQuery(const int l, const int r) {
    return rangeQuery(l, r, 1, 0, sn - 1);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    FOR(x, 0, m) {
        int i, l, r;
        cin >> i >> l >> r;
        arr[cnt++] = l;
        arr[cnt++] = r;
        intervals[i].push_back({l, r});
    }

    // compression
    sort(arr, arr + 2 * m);
    cnt = unique(arr, arr + 2 * m) - arr;

    FOR_(i, 1, n) {
        for (auto& v : intervals[i]) {
            v.first = lower_bound(arr, arr + cnt, v.first) - arr;
            v.second = lower_bound(arr, arr + cnt, v.second) - arr;
        }
    }

    // init tree size
    for (sn = 1; sn < cnt; sn <<= 1)
        ;

    FOR_(i, 1, n) {
        pii mx = {0, 0};
        for (auto& v : intervals[i]) {
            pii ret = rangeQuery(v.first, v.second);
            mx = max(mx, ret);
        }
        prv[i] = mx.second;
        pii x = {mx.first + 1, i};
        for (auto& v : intervals[i]) {
            rangeUpdate(v.first, v.second, x);
        }
    }

    pii x = rangeQuery(0, cnt - 1);
    int y = x.second;
    int z = n;

    ans = n - x.first;
    cout << ans << '\n';

    while (true) {
        while (z > y) {
            cout << z << ' ';
            z--;
        }
        if (y == 0)
            break;
        y = prv[y];
        z--;
    }
    cout << '\n';

    return 0;
}