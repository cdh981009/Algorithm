// 10999: 구간 합 구하기 2
// https://www.acmicpc.net/problem/10999
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = (1 << 18);
constexpr int X = 1e5;
constexpr int M = 1e9 + 7;

using ll = long long;
using pll = pair<ll, ll>;

int a, n, q;
int arr[X];
ll segTree[N];
pll lazy[N];

void initTree() {
    for (n = 1; n < a; n <<= 1);
    FOR(i, 0, n) {
        segTree[n + i] = (i < a ? arr[i] : 0);
    }
    for (int i = n - 1; i >= 1; --i)
        segTree[i] = (segTree[2 * i] + segTree[2 * i + 1]) % M;
    FOR(i, 1, 2 * n) {
        lazy[i] = {1, 0};
    }
}

void lazyUpdate(int node, int nodeLeft, int nodeRight) {
    auto op = [](ll &x, const pll& p, int r) {
        x *= p.first;
        x %= M;
        x += (p.second * r) % M;
        x %= M;
    };

    op(segTree[node], lazy[node], (nodeRight - nodeLeft + 1));

    if (nodeLeft != nodeRight) {
        op(lazy[2 * node].first, lazy[node], 0);
        op(lazy[2 * node].second, lazy[node], 1);

        op(lazy[2 * node + 1].first, lazy[node], 0);
        op(lazy[2 * node + 1].second, lazy[node], 1);
    }

    lazy[node] = {1, 0};
}

const int ADD = 1, MUL = 2, SET = 3;

void rangeUpdate(const int left, const int right, const ll x, int node, int nodeLeft, int nodeRight, int op) {
    lazyUpdate(node, nodeLeft, nodeRight);

    if (right < nodeLeft || nodeRight < left) {
        // node's range and query range do not overlap
        /* do nothing */
        return;
    }

    if (left <= nodeLeft && nodeRight <= right) {
        // node's range is completely inside query range
        if (op == ADD) {
            segTree[node] += (x * (nodeRight - nodeLeft + 1)) % M;
            segTree[node] %= M;
        } else if (op == MUL) {
            segTree[node] *= x;
            segTree[node] %= M;
        } else {
            segTree[node] = (x * (nodeRight - nodeLeft + 1)) % M;
        }

        if (nodeLeft != nodeRight) {
            if (op == ADD) {
                lazy[2 * node].second += x;
                lazy[2 * node].second %= M;
                lazy[2 * node + 1].second += x;
                lazy[2 * node + 1].second %= M;
            } else if (op == MUL) {
                lazy[2 * node].first *= x;
                lazy[2 * node].first %= M;

                lazy[2 * node].second *= x;
                lazy[2 * node].second %= M;

                lazy[2 * node + 1].first *= x;
                lazy[2 * node + 1].first %= M;

                lazy[2 * node + 1].second *= x;
                lazy[2 * node + 1].second %= M;
            } else {
                lazy[2 * node] = {0, x};
                lazy[2 * node + 1] = {0, x};
            }
        }
        return;
    }

    // node's range and query range partially overlaps,
    // or query range is inside node's range

    int mid = (nodeLeft + nodeRight) / 2;
    rangeUpdate(left, right, x, 2 * node, nodeLeft, mid, op);
    rangeUpdate(left, right, x, 2 * node + 1, mid + 1, nodeRight, op);

    segTree[node] = segTree[2 * node] + segTree[2 * node + 1];
    segTree[node] %= M;

    return;
}

void rangeUpdate(const int left, const int right, const ll x, int op) {
    rangeUpdate(left, right, x, 1, 0, n - 1, op);
}

ll rangeQuery(const int left, const int right, int node, int nodeLeft, int nodeRight) {
    lazyUpdate(node, nodeLeft, nodeRight);

    if (right < nodeLeft || nodeRight < left) {
        // node's range and query range do not overlap
        return 0;
    }

    if (left <= nodeLeft && nodeRight <= right) {
        // node's range is completely inside query range
        return segTree[node];
    }

    // node's range and query range partially overlaps,
    // or query range is inside node's range
    int mid = (nodeLeft + nodeRight) / 2;
    return (rangeQuery(left, right, 2 * node, nodeLeft, mid) +
           rangeQuery(left, right, 2 * node + 1, mid + 1, nodeRight)) % M;
}

long long rangeQuery(const int left, const int right) {
    return rangeQuery(left, right, 1, 0, n - 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> a;
    FOR(i, 0, a) {
        cin >> arr[i];
    }
    initTree();
    cin >> q;
    FOR(i, 0, q) {
        int type;
        cin >> type;
        int x, y, v;
        cin >> x >> y;
        x--, y--;
        if (type != 4) {
            cin >> v;
            rangeUpdate(x, y, v, type);
        } else {
            cout << rangeQuery(x, y) << '\n';
        }
    }
    return 0;
}