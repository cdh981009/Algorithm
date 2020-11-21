// 10999: 구간 합 구하기 2
// https://www.acmicpc.net/problem/10999
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = (1 << 20);
int n;

// xor segTree
int segTree[N];
int lazy[N];

void initTree(const vector<int>& arr) {
    for (n = 1; n < arr.size(); n <<= 1)
        ;
    // segTree size is 2 * n, 1-based
    // leaf init
    FOR(i, 0, n)
    segTree[n + i] = (i < arr.size() ? arr[i] : 0 /* default value */);
    for (int i = n - 1; i >= 1; --i)
        segTree[i] = segTree[2 * i] ^ segTree[2 * i + 1];
}

void lazyUpdate(int node, int nodeLeft, int nodeRight) {
    if (nodeLeft != nodeRight) {
        lazy[2 * node] ^= lazy[node];
        lazy[2 * node + 1] ^= lazy[node];
    } else {
        segTree[node] ^= lazy[node];
    }

    lazy[node] = 0;
}

void rangeUpdate(const int left, const int right, const int x, int node, int nodeLeft, int nodeRight) {
    lazyUpdate(node, nodeLeft, nodeRight);

    if (right < nodeLeft || nodeRight < left) {
        // node's range and query range do not overlap
        /* do nothing */
        return;
    }

    if (left <= nodeLeft && nodeRight <= right) {
        // node's range is completely inside query range
        if (nodeLeft != nodeRight) {
            lazy[2 * node] ^= x;
            lazy[2 * node + 1] ^= x;
        } else {
            segTree[node] ^= x;
        }

        return;
    }

    // node's range and query range partially overlaps,
    // or query range is inside node's range

    int mid = (nodeLeft + nodeRight) / 2;
    rangeUpdate(left, right, x, 2 * node, nodeLeft, mid);
    rangeUpdate(left, right, x, 2 * node + 1, mid + 1, nodeRight);

    segTree[node] = segTree[2 * node] ^ segTree[2 * node + 1];
    return;
}

void rangeUpdate(const int left, const int right, const int x) {
    rangeUpdate(left, right, x, 1, 0, n - 1);
}

int rangeQuery(const int left, const int right, int node, int nodeLeft, int nodeRight) {
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
    return rangeQuery(left, right, 2 * node, nodeLeft, mid) ^
           rangeQuery(left, right, 2 * node + 1, mid + 1, nodeRight);
}

int rangeQuery(const int left, const int right) {
    return rangeQuery(left, right, 1, 0, n - 1);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr;
    arr.reserve(n);

    FOR(i, 0, n) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    initTree(arr);

    int q;
    cin >> q;
    FOR(i, 0, q) {
        int type;
        cin >> type;
        int s, e;
        cin >> s >> e;
        if (type == 1) {
            int x;
            cin >> x;
            rangeUpdate(s, e, x); // not intended
        } else {
            cout << rangeQuery(s, e) << '\n';
        }
    }
    return 0;
}