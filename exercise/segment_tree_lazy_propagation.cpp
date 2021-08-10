// 10999: 구간 합 구하기 2
// https://www.acmicpc.net/problem/10999
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = (1 << 21);
int sn;

ll seg[N];
ll lazy[N];

// sum tree

void init(const vector<ll>& arr) {
    for (sn = 1; sn < arr.size(); sn <<= 1)
        ;
    // leaf init
    FOR(i, 0, sn) {
        seg[sn + i] = (i < arr.size() ? arr[i] : 0 /* default value */);
    }
    for (int i = sn - 1; i >= 1; --i)
        seg[i] = seg[2 * i] + seg[2 * i + 1];
}

void prpgt(int node, int nodeL, int nodeR) {
    seg[node] += lazy[node] * (nodeR - nodeL + 1);

    if (nodeL != nodeR) {
        lazy[2 * node] += lazy[node];
        lazy[2 * node + 1] += lazy[node];
    }

    lazy[node] = 0;
}

// add x to all elements in range [l, r]
void rangeUpdate(int l, int r, ll x, int node, int nodeL, int nodeR) {
    prpgt(node, nodeL, nodeR);

    if (r < nodeL || nodeR < l) {
        return;
    }

    if (l <= nodeL && nodeR <= r) {
        seg[node] += x * (nodeR - nodeL + 1);

        if (nodeL != nodeR) {
            lazy[2 * node] += x;
            lazy[2 * node + 1] += x;
        }
        return;
    }

    int mid = (nodeL + nodeR) / 2;
    rangeUpdate(l, r, x, 2 * node, nodeL, mid);
    rangeUpdate(l, r, x, 2 * node + 1, mid + 1, nodeR);

    seg[node] = seg[2 * node] + seg[2 * node + 1];
    return;
}

void rangeUpdate(const int l, const int r, const ll x) {
    rangeUpdate(l, r, x, 1, 0, sn - 1);
}

ll rangeQuery(const int l, const int r, int node, int nodeL, int nodeR) {
    prpgt(node, nodeL, nodeR);

    if (r < nodeL || nodeR < l)
        return 0;

    if (l <= nodeL && nodeR <= r)
        return seg[node];

    int mid = (nodeL + nodeR) / 2;
    return rangeQuery(l, r, 2 * node, nodeL, mid) +
           rangeQuery(l, r, 2 * node + 1, mid + 1, nodeR);
}

ll rangeQuery(const int l, const int r) {
    return rangeQuery(l, r, 1, 0, sn - 1);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<ll> arr;
    arr.reserve(n);

    FOR(i, 0, n) {
        ll x;
        cin >> x;
        arr.push_back(x);
    }

    init(arr);

    FOR(i, 0, m + k) {
        int type;
        cin >> type;
        int s, e;
        cin >> s >> e;
        s--;
        e--;
        if (type == 1) {
            ll x;
            cin >> x;
            rangeUpdate(s, e, x); // not intended
        } else {
            cout << rangeQuery(s, e) << '\n';
        }
    }
    return 0;
}