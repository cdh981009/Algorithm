// 16357: Circuits
// https://www.acmicpc.net/problem/16357
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = (1 << 19);
int n;

int segTree[N];
int lazy[N];

void lazyUpdate(int node, int nodeLeft, int nodeRight) {
    if (lazy[node] == 0)
        return;

    segTree[node] += lazy[node];

    if (nodeLeft != nodeRight) {
        lazy[2 * node] += lazy[node];
        lazy[2 * node + 1] += lazy[node];
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

        segTree[node] += x;

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

    segTree[node] = max(segTree[2 * node], segTree[2 * node + 1]);
    return;
}

inline void rangeUpdate(const int left, const int right, const int x) {
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
    return max(rangeQuery(left, right, 2 * node, nodeLeft, mid),
            rangeQuery(left, right, 2 * node + 1, mid + 1, nodeRight));
}

inline int rangeQuery(const int left, const int right) {
    return rangeQuery(left, right, 1, 0, n - 1);
}

void releaseLazy(int node, int nodeLeft, int nodeRight) {
    lazyUpdate(node, nodeLeft, nodeRight);

    if (nodeLeft != nodeRight) {
        int mid = (nodeLeft + nodeRight) / 2;
        releaseLazy(2 * node, nodeLeft, mid);
        releaseLazy(2 * node + 1, mid + 1, nodeRight);
    }
}

inline void releaseLazy() {
    releaseLazy(1, 0, n - 1);
}

inline int unsafePointQuery(const int ind) {
    return segTree[ind + n];
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> lines;
    vector<int> ys;

    map<int, int> yToIndex;

    FOR(i, 0, n) {
        int dump, yBig, ySmall;
        cin >> dump >> yBig >> dump >> ySmall;

        lines.push_back({ySmall, yBig});
        ys.push_back(ySmall);
        ys.push_back(yBig);
    }

    // y coord compression
    sort(ys.begin(), ys.end());
    auto u = unique(ys.begin(), ys.end());
    if (u != ys.end())
        ys.erase(u, ys.end());
    for (auto y : ys) {
        yToIndex[y] = yToIndex.size();
    }
    for (auto& p : lines) {
        p.first = yToIndex[p.first];
        p.second = yToIndex[p.second];
    }

    // init seg tree
    for (::n = 1; ::n < yToIndex.size(); ::n <<= 1)
        ;
    for (const auto& p : lines) {
        rangeUpdate(p.first, p.second, 1);
    }

    vector<int> arr(yToIndex.size());
    releaseLazy();
    FOR(i, 0, arr.size()) {
        arr[i] = unsafePointQuery(i);
    }

    sort(lines.begin(), lines.end());
    int lineInd = 0;
    int ans = 0;
    FOR(i, 0, yToIndex.size()) {
        // set i as one of the two horizontal line, find optimal pair.

        // two pointer-like approach
        // Amortized time complexity is O(n log n)
        while (lineInd < lines.size()) {
            const auto& l = lines[lineInd];
            if (l.first <= i) {
                lineInd++;
                rangeUpdate(l.first, l.second, -1);
            } else {
                break;
            }
        }

        int res = arr[i] + rangeQuery(0, yToIndex.size());

        ans = max(ans, res);
    }

    cout << ans << '\n';

    return 0;
}