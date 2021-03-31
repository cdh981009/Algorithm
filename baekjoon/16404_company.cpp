// 16404: 주식회사 승범이네
// https://www.acmicpc.net/problem/16404
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

const int N = 101010;
const int X = 1 << 18;

int n, m;

int segN;
int seg[X];
int lazy[X];
int segCnt = 0;

int toSeg[N];
int toSegSub[N];

// sum tree
void constructTree() {
    for (segN = 1; segN < n; segN <<= 1)
        ;
}

void propagate(int node, int nodeLeft, int nodeRight) {
    if (lazy[node] == 0)
        return;

    int k = lazy[node];

    seg[node] += k;
    lazy[node] = 0;

    if (node < segN) {
        lazy[2 * node] += k;
        lazy[2 * node + 1] += k;
    }
}

void update(int left, int right, int node, int nodeLeft, int nodeRight, int k) {
    propagate(node, nodeLeft, nodeRight);

    if (right < nodeLeft || nodeRight < left) {
        return;
    } else if (left <= nodeLeft && nodeRight <= right) {
        // fully overlaps
        seg[node] += k;

        if (node < segN) {
            lazy[2 * node] += k;
            lazy[2 * node + 1] += k;
        }
    } else {
        // partially overlaps
        int mid = (nodeLeft + nodeRight) / 2;
        update(left, right, 2 * node, nodeLeft, mid, k);
        update(left, right, 2 * node + 1, mid + 1, nodeRight, k);
    }
}

void update(int x, int y, int k) {
    update(x, y, 1, 0, segN - 1, k);
}

int query(int left, int right, int node, int nodeLeft, int nodeRight) {
    propagate(node, nodeLeft, nodeRight);

    if (right < nodeLeft || nodeRight < left) {
        return 0;
    } else if (left <= nodeLeft && nodeRight <= right) {
        // fully overlaps
        return seg[node];
    } else {
        // partially overlaps
        int mid = (nodeLeft + nodeRight) / 2;
        int l = query(left, right, 2 * node, nodeLeft, mid);
        int r = query(left, right, 2 * node + 1, mid + 1, nodeRight);
        return l + r;
    }
}

int query(int x) {
    return query(x, x, 1, 0, segN - 1);
}

vector<int> children[N];

void dfs(int node) {
    toSeg[node] = segCnt++;

    FOR(i, 0, children[node].size()) {
        int child = children[node][i];
        dfs(child);
    }

    toSegSub[node] = segCnt - 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    constructTree();

    FOR(i, 0, n) {
        int p; cin >> p;
        p--;
        if (p >= 0)
            children[p].push_back(i);
    }   

    dfs(0);

    FOR(i, 0, m) {
        int q;
        cin >> q;
        if (q == 1) {
            int x, k;
            cin >> x >> k;
            x--;
            update(toSeg[x], toSegSub[x], k);
        } else {
            int x; cin >> x;
            x--;
            cout << query(toSeg[x]) << '\n';
        }
    }

    return 0;
}