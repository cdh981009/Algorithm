// 10999: 구간 합 구하기 2
// https://www.acmicpc.net/problem/10999
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = (1 << 21);
int n;

long long segTree[N];
long long lazy[N];

void initTree(const vector<long long>& arr) {
    for (n = 1; n < arr.size(); n <<= 1)
        ;
    // segTree size is 2 * n, 1-based
    // leaf init
    FOR(i, 0, n)
    segTree[n + i] = (i < arr.size() ? arr[i] : 0 /* default value */);
    for (int i = n - 1; i >= 1; --i)
        segTree[i] = segTree[2 * i] + segTree[2 * i + 1];
}

void lazyUpdate(int node, int nodeLeft, int nodeRight) {
    segTree[node] += lazy[node] * (nodeRight - nodeLeft + 1);

    if (nodeLeft != nodeRight) {
        lazy[2 * node] += lazy[node];
        lazy[2 * node + 1] += lazy[node];
    }

    lazy[node] = 0;
}

void rangeUpdate(const int left, const int right, const long long x, int node, int nodeLeft, int nodeRight) {
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

void rangeUpdate(const int left, const int right, const long long x) {
    rangeUpdate(left, right, x, 1, 0, n - 1);
}

long long rangeQuery(const int left, const int right, int node, int nodeLeft, int nodeRight) {
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

long long rangeQuery(const int left, const int right) {
    return rangeQuery(left, right, 1, 0, n - 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<long long> arr;
    arr.reserve(n);

    FOR(i, 0, n) {
        long long x;
        cin >> x;
        arr.push_back(x);
    }

    initTree(arr);

    FOR(i, 0, m + k) {
        int type;
        cin >> type;
        int s, e;
        cin >> s >> e;
        s--;
        e--;
        if (type == 1) {
            long long x;
            cin >> x;
            rangeUpdate(s, e, x); // not intended
        } else {
            cout << rangeQuery(s, e) << '\n';
        }
    }
    return 0;
}