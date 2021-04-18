// 16978: 수열과 쿼리 22
// https://www.acmicpc.net/problem/16978
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

// practice persistent seg tree

constexpr int N = 101010;

using ll = long long;

int arr[N];
int n, q;
int sn;

struct Node {
    Node *l, *r;
    long long val;
    Node() {
        l = r = nullptr;
        val = 0;
    }
} * root[N];

int qCnt = 0;

void buildTree(Node* node, int l, int r) {
    if (l != r) {
        node->l = new Node();
        node->r = new Node();
        int mid = (l + r) / 2;
        buildTree(node->l, l, mid);
        buildTree(node->r, mid + 1, r);
        node->val = node->l->val + node->r->val;
    } else {
        node->val = l < n ? arr[l] : 0;
    }
}

void init() {
    sn = 1;
    while (sn < n)
        sn <<= 1;

    root[0] = new Node();
    buildTree(root[0], 0, sn - 1);
}

void update(Node* node, Node* old, int l, int r, int target, int val) {
    if (l != r) {
        int mid = (l + r) / 2;
        if (target <= mid) {
            node->l = new Node();
            node->r = old->r;
            update(node->l, old->l, l, mid, target, val);
            node->val = node->l->val + node->r->val;
        } else {
            node->l = old->l;
            node->r = new Node();
            update(node->r, old->r, mid + 1, r, target, val);
            node->val = node->l->val + node->r->val;
        }
    } else {
        node->val = val;
    }
}

void update(int x, int v) {
    root[++qCnt] = new Node();
    update(root[qCnt], root[qCnt - 1], 0, sn - 1, x, v);
}

long long query(Node* node, int l, int r, int nodeL, int nodeR) {
    if (r < nodeL || nodeR < l)
        return 0;
    
    if (l <= nodeL && nodeR <= r) {
        return node->val;
    }

    int mid = (nodeL + nodeR) / 2;
    return query(node->l, l, r, nodeL, mid) + query(node->r, l, r, mid + 1, nodeR);
}

long long query(int stage, int x, int y) {
    return query(root[stage], x, y, 0, sn - 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 0, n) {
        cin >> arr[i];
    }
    init();
    cin >> q;
    FOR(i, 0, q) {
        int t; cin >> t;
        int x, y, z;
        if (t == 1) {
            cin >> x >> y;
            update(x - 1, y);
        } else {
            cin >> x >> y >> z;
            cout << query(x, y - 1, z - 1) << '\n';
        }
    }

    return 0;
}