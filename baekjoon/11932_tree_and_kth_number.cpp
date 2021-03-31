// 11932: 트리와 K번째 수
// https://www.acmicpc.net/problem/11932
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

const int N = 1010; //10;

// heavy-light decomposition

int n, m;
vector<int> edges[N];
int parent[N];
int subtree[N];
int depth[N];

int value[N];

int segN;

int segHead[N];
int segIndex[N];

int segCnt = 0;
vector<int> segArr;
vector<vector<int>> seg;

// merge sort tree
void constructTree() {
    for (segN = 1; segN <= n; segN <<= 1)
        ;
    seg.resize(2 * segN);
    FOR(i, 0, n) {
        seg[i + segN].push_back(segArr[i]);
    }
    for (int i = segN - 1; i >= 1; --i) {
        seg[i].resize(seg[2 * i].size() + seg[2 * i + 1].size());
        merge(seg[2 * i].begin(),     seg[2 * i].end(),
              seg[2 * i + 1].begin(), seg[2 * i + 1].end(),
              seg[i].begin());
    }
}

int query(int x, int y, int k) {
    int res;

    vector<vector<int>> vectors;
    // find lca
    while (segHead[x] != segHead[y]) {
        if (depth[segHead[x]] == depth[segHead[y]]) {
            vectors.push_back()
            x = parent[segHead[x]];
            y = parent[segHead[y]];
        } else if (depth[segHead[x]] > depth[segHead[y]]) {
            x = parent[segHead[x]];
        } else {
            y = parent[segHead[y]];
        }
    }
    // parametric search for kth element
    // O(log^2(n) * log(1e9))
    return res = 0;
}

void hld(int node, int par) {
    segArr[segCnt++] = node;
    segIndex[node] = segCnt;

    int maxSize = 0;
    int maxInd = -1;
    for (auto& child : edges[node]) {
        if (child == par)
            continue;
        if (maxSize < subtree[child]) {
            maxSize = subtree[child];
            maxInd = child;
        }
    }

    // primary chain
    if (maxInd != -1) {
        segHead[maxInd] = segHead[node];
        hld(maxInd, node);
    }

    // branch chain
    for (auto& child : edges[node]) {
        if (child == par || child == maxInd)
            continue;
        segHead[child] = child;
        hld(child, node);
    }
}

int dfs(int node, int par) {
    subtree[node] = 1;

    for (auto& child : edges[node]) {
        if (child == par)
            continue;
        parent[child] = node;
        depth[child] = depth[node] + 1;
        subtree[node] += dfs(child, node);
    }

    return subtree[node];
}

void hld() {
    dfs(0, 0);

    segArr.resize(N);
    hld(0, 0);

    constructTree();
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    FOR(i, 0, n) {
        cin >> value[i];
    }

    FOR(i, 0, n - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    hld();

    FOR(i, 0, m) {
        int x, y, k;
        cin >> x >> y >> k;
        x--;
        y--;
        cout << query(x, y, k) << '\n';
    }

    return 0;
}