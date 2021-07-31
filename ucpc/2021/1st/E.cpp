#include <bits/stdc++.h>

using namespace std;

#define INF 1e18
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 101010;
constexpr int M = (1 << 18);

using ll = long long;
using pii = pair<int, int>;

ll ans = INT64_MAX;
int H[N], A[N], B[N];
int n, k;
ll c;

int sn;

ll segTree[M];
ll lazy[M];

void init() {
    for (sn = 1; sn < 1e5 + 1; sn <<= 1)
        ;
}

void lazyUpdate(int node, int nodeLeft, int nodeRight) {
    segTree[node] += lazy[node] * (nodeRight - nodeLeft + 1);

    if (nodeLeft != nodeRight) {
        lazy[2 * node] += lazy[node];
        lazy[2 * node + 1] += lazy[node];
    }

    lazy[node] = 0;
}

void rangeUpdate(const int left, const int right, const ll x, int node, int nodeLeft, int nodeRight) {
    lazyUpdate(node, nodeLeft, nodeRight);

    if (right < nodeLeft || nodeRight < left) {
        // node's range and query range do not overlap
        /* do nothing */
        return;
    }

    if (left <= nodeLeft && nodeRight <= right) {
        // node's range is completely inside query range
        segTree[node] += x * (nodeRight - nodeLeft + 1);

        if (nodeLeft != nodeRight) {
            lazy[2 * node] += x;
            lazy[2 * node + 1] += x;
        }
        return;
    }

    // node's range and query range partially overlaps,
    // or query range is inside node's range

    int mid = (nodeLeft + nodeRight) / 2;
    rangeUpdate(left, right, x, 2 * node, nodeLeft, mid);
    rangeUpdate(left, right, x, 2 * node + 1, mid + 1, nodeRight);

    segTree[node] = segTree[2 * node] + segTree[2 * node + 1];
    return;
}

void rangeUpdate(const int left, const int right, const ll x) {
    rangeUpdate(left, right, x, 1, 0, sn - 1);
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
    return rangeQuery(left, right, 2 * node, nodeLeft, mid) +
           rangeQuery(left, right, 2 * node + 1, mid + 1, nodeRight);
}

ll rangeQuery(const int left, const int right) {
    return rangeQuery(left, right, 1, 0, sn - 1);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    FOR(i, 0, n) {
        cin >> H[i];
    }
    FOR(i, 0, n) {
        cin >> A[i];
    }
    FOR(i, 0, n) {
        cin >> B[i];
    }

    init();

    int mx = 1e5;

    FOR_(i, 0, n - k) {
        if (i == 0) {
            // 0 .. k - 1 넣기
            FOR_(j, 0, k - 1) {
                rangeUpdate(0, H[j], -B[j]);
                rangeUpdate(H[j] + 1, 1e5 + 1, +A[j]);
                c += B[j] * H[j];
            }
        } else {
            // i - 1 빼기
            rangeUpdate(0, H[i - 1], +B[i - 1]);
            rangeUpdate(H[i - 1] + 1, 1e5 + 1, -A[i - 1]);
            c -= B[i - 1] * H[i - 1];

            rangeUpdate(0, H[i + k - 1], -B[i + k - 1]);
            rangeUpdate(H[i + k - 1] + 1, 1e5 + 1, +A[i + k - 1]);
            c += B[i + k - 1] * H[i + k - 1];
        }

        // parametric search
        int x = 0;
        for (int step = mx; step >= 1; step /= 2) {
            while (x + step <= mx && rangeQuery(x + step, x + step) < 0)
                x += step;
        }

        ans = min(ans, c + rangeQuery(1, x));
    }

    cout << ans << '\n';

    return 0;
}