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
// 트리 펼치기 때문에 트리 leaf의 크기가 2 * N 이므로 필요한 노드 양이 많다
const int NN = 40 * N;
const int LN = 18;

int n, m;

// num of leafs in segment tree(power of 2)
int sn = 1 << LN;

int value[N];
int sorted[N];

vector<int> edges[N];
int par[N][LN];
int depth[N];
int sInd[N];
int eInd[N];

// persistent segment tree (count tree)
int nl[NN], nr[NN], nv[NN];
int nodeCnt = 0;

// root node for i-th stage;
int currStage = 0;
int root[2 * N];

void buildTree(int nInd, int s, int e) {
    if (s == e)
        return;
    int mid = (s + e) / 2;
    nl[nInd] = nodeCnt++;
    buildTree(nl[nInd], s, mid);

    nr[nInd] = nodeCnt++;
    buildTree(nr[nInd], mid + 1, e);
}

void pointUpdate(int nInd, int oInd, int nodeLeft, int nodeRight, int ind, int v) {
    if (nodeLeft == nodeRight) {
        nv[nInd] = v;
        return;
    }

    int mid = (nodeLeft + nodeRight) / 2;

    if (ind <= mid) {
        nl[nInd] = nodeCnt++;
        nr[nInd] = nr[oInd];
        pointUpdate(nl[nInd], nl[oInd], nodeLeft, mid, ind, v);
    } else {
        nl[nInd] = nl[oInd];
        nr[nInd] = nodeCnt++;
        pointUpdate(nr[nInd], nr[oInd], mid + 1, nodeRight, ind, v);
    }

    nv[nInd] = nv[nl[nInd]] + nv[nr[nInd]];
}

void initTree() {
    // construct default tree
    root[0] = nodeCnt++;
    buildTree(root[0], 0, sn - 1);
}

void dfs(int node) {
    // enter
    root[++currStage] = nodeCnt++;
    sInd[node] = currStage;
    pointUpdate(root[currStage], root[currStage - 1], 0, sn - 1, value[node], 1);

    // traverse children
    for (auto& child : edges[node]) {
        if (child == par[node][0])
            continue;
        par[child][0] = node;
        depth[child] = depth[node] + 1;
        dfs(child);
    }

    // leave
    root[++currStage] = nodeCnt++;
    eInd[node] = currStage;
    pointUpdate(root[currStage], root[currStage - 1], 0, sn - 1, value[node], 0);
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
        int cnt = nv[nl[nx]] + nv[nl[ny]] - nv[nl[nz]] - nv[nl[nw]];
        if (cnt >= k) {
            nx = nl[nx];
            ny = nl[ny];
            nz = nl[nz];
            nw = nl[nw];
            r = mid;
        }
        else {
            k -= cnt;
            nx = nr[nx];
            ny = nr[ny];
            nz = nr[nz];
            nw = nr[nw];
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
        int x;
        cin >> x;
        value[i] = x;
        sorted[i] = x;
    }

    // compression
    sort(sorted, sorted + n);
    FOR(i, 0, n) {
        value[i] = lower_bound(sorted, sorted + n, value[i]) - sorted;
    }

    FOR(i, 0, n - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
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
        cin >> x >> y >> k;
        x--;
        y--;
        cout << query(x, y, k) << '\n';
    }

    return 0;
}