// 11932: 트리와 K번째 수
// https://www.acmicpc.net/problem/11932
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

// const int N = 20;
// const int X = 1 << 10;

const int N = 101010;
const int LN = 18;
const int X = 1 << LN;

int n, m;

// num of leafs in segment tree(power of 2)
int sn;

int value[N];
int sorted[N];
map<int, int> val2Seg;

vector<int> edges[N];
int par[N][LN];
int depth[N];
int sInd[N];
int eInd[N];

// persistent segment tree (count tree)
struct Node {
    int value = 0;
    Node* left = nullptr;
    Node* right = nullptr;
};

// root node for i-th stage;
int currStage = 0;
Node* root[2 * N];

void buildTree(Node* node, int s, int e) {
    if (s == e)
        return;
    node->left = new Node;
    node->right = new Node;
    int mid = (s + e) / 2;
    buildTree(node->left, s, mid);
    buildTree(node->right, mid + 1, e);
}

void pointUpdate(Node* node, Node* old, int nodeLeft, int nodeRight, int ind, int v) {
    if (nodeLeft == nodeRight) {
        node->value = v;
        return;
    }

    int mid = (nodeLeft + nodeRight) / 2;

    if (ind <= mid) {
        node->left = new Node;
        node->right = old->right;
        pointUpdate(node->left, old->left, nodeLeft, mid, ind, v);
    } else {
        node->left = old->left;
        node->right = new Node;
        pointUpdate(node->right, old->right, mid + 1, nodeRight, ind, v);
    }

    node->value = node->left->value + node->right->value;
}

void initTree() {
    for (sn = 1; sn < n; sn <<= 1);
    // construct default tree
    root[0] = new Node;
    buildTree(root[0], 0, sn - 1);
}

void dfs(int node) {
    // enter
    root[++currStage] = new Node;
    sInd[node] = currStage;
    pointUpdate(root[currStage], root[currStage - 1], 0, sn - 1, val2Seg[value[node]], 1);

    // traverse children
    for (auto& child : edges[node]) {
        if (child == par[node][0])
            continue;
        par[child][0] = node;
        depth[child] = depth[node] + 1;
        dfs(child);
    }

    // leave
    root[++currStage] = new Node;
    eInd[node] = currStage;
    pointUpdate(root[currStage], root[currStage - 1], 0, sn - 1, val2Seg[value[node]], 0);
}

int lca(int x, int y) {
    if (depth[x] < depth[y])
        swap(x, y);

    for (int i = LN - 1; i >= 0; --i) {
        int xx = par[x][i];
        if (depth[xx] >= depth[y])
            x = xx;
    }
    
    if (x == y)
        return x;

    for (int i = LN - 1; i >= 0; --i) {
        int xx = par[x][i];
        int yy = par[y][i];
        if (xx != yy) {
            x = xx;
            y = yy;
        }
    }

    return par[x][0];
}

int query(int x, int y, int k) {
    int l = 0, r = sn - 1;
    int a = lca(x, y);
    auto nx = root[sInd[x]];
    auto ny = root[sInd[y]];
    auto nz = root[sInd[a]];
    auto nw = root[sInd[a] - 1];

    while (l != r) {
        int mid = (l + r) / 2;
        int cnt = nx->left->value + ny->left->value
                - nz->left->value - nw->left->value;
        if (cnt >= k) {
            nx = nx->left;
            ny = ny->left;
            nz = nz->left;
            nw = nw->left;
            r = mid;
        } else {
            k -= cnt;
            nx = nx->right;
            ny = ny->right;
            nz = nz->right;
            nw = nw->right;
            l = mid + 1;
        }
    }

    return sorted[l];
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    FOR(i, 0, n) {
        int x; cin >> x;
        value[i] = x;
        sorted[i] = x;
    }

    // compression
    sort(sorted, sorted + n);
    FOR(i, 0, n) {
        val2Seg[sorted[i]] = i;
    }

    FOR(i, 0, n - 1) {
        int a, b; cin >> a >> b; a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    initTree();
    dfs(0);

    // lca info
    FOR(i, 1, LN) {
        FOR(j, 0, n) {
            par[j][i] = par[par[j][i - 1]][i - 1];
        }
    }

    FOR(i, 0, m) {
        int x, y, k;
        cin >> x >> y >> k; x--; y--;
        cout << query(x, y, k) << '\n';
    }

    return 0;
}