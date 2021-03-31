// 8339: Fibonacci Machine
// https://www.acmicpc.net/problem/8339
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

const int N = 101010;
const int X = 1 << 18;
const int M = 1e9 + 7;

int n, k;

int segN;
int fCurr[X];
int fPrev[X];
int lazy[X];

int fib[N];

void getFib() {
    fib[0] = 0;
    fib[1] = 1;
    FOR(i, 2, N) {
        fib[i] = fib[i - 1] + fib[i - 2];
        fib[i] %= M;
    }
}

// sum tree
void constructTree() {
    for (segN = 1; segN < n; segN <<= 1)
        ;
    for (int i = 0; i < segN; ++i) {
        fCurr[i + segN] = 0;
        fPrev[i + segN] = 1;
    }
    for (int i = segN - 1; i >= 1; --i) {
        fCurr[i] = fCurr[2 * i] + fCurr[2 * i + 1];
        fPrev[i] = fPrev[2 * i] + fPrev[2 * i + 1];
    }
}

// sum(fib(m + k)) = f(k + 1) * sum(fib(m))
//                 + f(k)     * sum(fib(m - 1))
void updateFib(int node, int k) {
    long long newfCurr = ((long long)fib[k + 1] * fCurr[node]) % M;
    newfCurr += ((long long)fib[k] * fPrev[node]) % M;
    newfCurr %= M;

    long long newfPrev = ((long long)fib[k] * fCurr[node]) % M;
    newfPrev += ((long long)fib[k - 1] * fPrev[node]) % M;
    newfPrev %= M;

    fCurr[node] = newfCurr;
    fPrev[node] = newfPrev;
}

void propagate(int node, int nodeLeft, int nodeRight) {
    if (lazy[node] == 0)
        return;

    int k = lazy[node];
    updateFib(node, k);

    lazy[node] = 0;

    if (node < segN) {
        lazy[2 * node] += k;
        lazy[2 * node + 1] += k;
    }
}

void update(int left, int right, int node, int nodeLeft, int nodeRight) {
    propagate(node, nodeLeft, nodeRight);

    if (right < nodeLeft || nodeRight < left) {
        return;
    } else if (left <= nodeLeft && nodeRight <= right) {
        // fully overlaps
        updateFib(node, 1);
        if (node < segN) {
            lazy[2 * node]++;
            lazy[2 * node + 1]++;
        }
    } else {
        // partially overlaps
        int mid = (nodeLeft + nodeRight) / 2;
        update(left, right, 2 * node, nodeLeft, mid);
        update(left, right, 2 * node + 1, mid + 1, nodeRight);

        fCurr[node] = fCurr[2 * node] + fCurr[2 * node + 1];
        fCurr[node] %= M;

        fPrev[node] = fPrev[2 * node] + fPrev[2 * node + 1];
        fPrev[node] %= M;
    }
}

void update(int x, int y) {
    update(x, y, 1, 0, segN - 1);
}

int query(int left, int right, int node, int nodeLeft, int nodeRight) {
    propagate(node, nodeLeft, nodeRight);

    if (right < nodeLeft || nodeRight < left) {
        return 0;
    } else if (left <= nodeLeft && nodeRight <= right) {
        // fully overlaps
        return fCurr[node];
    } else {
        // partially overlaps
        int mid = (nodeLeft + nodeRight) / 2;
        int l = query(left, right, 2 * node, nodeLeft, mid);
        int r = query(left, right, 2 * node + 1, mid + 1, nodeRight);
        return (l + r) % M;
    }
}

int query(int x, int y) {
    return query(x, y, 1, 0, segN - 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    getFib();

    cin >> n >> k;
    constructTree();
    FOR(i, 0, k) {
        char q;
        int x, y;
        cin >> q >> x >> y;
        x--;
        y--;
        if (q == 'D') {
            update(x, y);
        } else {
            cout << query(x, y) << '\n';
        }
    }
    return 0;
}