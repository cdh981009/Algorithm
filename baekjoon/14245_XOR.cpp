// 14245: XOR
// https://www.acmicpc.net/problem/14245
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = (1 << 21);
constexpr int M = 5e5;
int n;

// xor seg
int lazy[N];
int leaf[M];

void init() {
    int newN = 1;
    while (newN < n)
        newN <<= 1;
    n = newN;
}

void propagate(int node, int nodeLeft, int nodeRight) {
    if (nodeLeft != nodeRight) {
        lazy[2 * node] ^= lazy[node];
        lazy[2 * node + 1] ^= lazy[node];
    } else {
        leaf[nodeLeft] ^= lazy[node];
    }

    lazy[node] = 0;
}

void rangeUpdate(const int left, const int right, const int x, int node, int nodeLeft, int nodeRight) {
    propagate(node, nodeLeft, nodeRight);

    if (right < nodeLeft || nodeRight < left) {
        return;
    } else if (left <= nodeLeft && nodeRight <= right) {
        if (nodeLeft != nodeRight) {
            lazy[2 * node] ^= x;
            lazy[2 * node + 1] ^= x;
        } else {
            leaf[nodeLeft] ^= x;
        }
    } else {
        int mid = (nodeLeft + nodeRight) / 2;
        rangeUpdate(left, right, x, 2 * node, nodeLeft, mid);
        rangeUpdate(left, right, x, 2 * node + 1, mid + 1, nodeRight);
    }
}

void rangeUpdate(const int left, const int right, const int x) {
    rangeUpdate(left, right, x, 1, 0, n - 1);
}

int pointQuery(int ind, int node, int nodeLeft, int nodeRight) {
    propagate(node, nodeLeft, nodeRight);

    if (nodeLeft == nodeRight) {
        return leaf[nodeLeft];
    }

    int mid = (nodeLeft + nodeRight) / 2;
    if (ind <= mid) {
        return pointQuery(ind, 2 * node, nodeLeft, mid);
    } else {
        return pointQuery(ind, 2 * node + 1, mid + 1, nodeRight);
    }
}

int pointQuery(int ind) {
    return pointQuery(ind, 1, 0, n - 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 0, n) {
        cin >> leaf[i];
    }

    init();

    int q;
    cin >> q;
    FOR(i, 0, q) {
        int type, s, e, c;
        cin >> type;
        if (type == 1) {
            cin >> s >> e >> c;
            rangeUpdate(s, e, c);
        } else {
            cin >> s;
            cout << pointQuery(s) << '\n';
        }
    }
    return 0;
}