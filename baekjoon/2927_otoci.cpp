// 2927: OTOCI
// https://www.acmicpc.net/problem/2927
#include <bits/stdc++.h>

using namespace std;

#define INF 1987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

const int N = 3e4;
const int X = (1 << 16);

// heavy light decomposition
// lazy segment tree
int n, q;

int root[N];
bool visited[N];

vector<int> edge[N];
int depth[N];
int subtree[N];
int parent[N];

int chainHead[N];
int segIndex[N];

int cnt = 0;

int sn;
int seg[X];
int arr[N];

struct Query {
    int type;
    int x;
    int y;
} queries[(int)3e5];

void initSeg() {
    sn = 1;
    while (sn < n)
        sn <<= 1;
}

void dfs(int node) {
    subtree[node] = 1;
    visited[node] = true;
    for (auto child : edge[node]) {
        if (visited[child])
            continue;
        parent[child] = node;
        depth[child] = depth[node] + 1;
        dfs(child);
        subtree[node] += subtree[child];
    }
}

void update(int ind, int val) {
    ind += sn;
    seg[ind] = val;
    while ((ind /= 2) >= 1) {
        seg[ind] = seg[2 * ind] + seg[2 * ind + 1];
    }
}

void hld(int node) {
    segIndex[node] = cnt++;
    visited[node] = true;
    update(segIndex[node], arr[node]);

    int heavy = -1;
    int maxSub = 0;
    for (auto child : edge[node]) {
        if (child == parent[node])
            continue;
        if (maxSub < subtree[child]) {
            maxSub = subtree[child];
            heavy = child;
        }
    }

    if (heavy != -1) {
        chainHead[heavy] = chainHead[node];
        hld(heavy);
    }

    for (auto child : edge[node]) {
        if (child == parent[node] || child == heavy)
            continue;
        chainHead[child] = child;
        hld(child);
    }
}

int subQuery(int l, int r) {
    l += sn;
    r += sn;
    int sum = 0;
    while (l <= r) {
        if (l % 2 == 1) {
            sum += seg[l++];
        }
        if (r % 2 == 0) {
            sum += seg[r--];
        }
        l /= 2;
        r /= 2;
    }
    return sum;
}

int query(int x, int y) {
    int sum = 0;
    while (chainHead[x] != chainHead[y]) {
        int xx = chainHead[x];
        int yy = chainHead[y];
        if (depth[xx] < depth[yy]) {
            swap(x, y);
            swap(xx, yy);
        }
        sum += subQuery(segIndex[xx], segIndex[x]);
        x = parent[xx];
    }
    if (depth[x] > depth[y])
        swap(x, y);
    sum += subQuery(segIndex[x], segIndex[y]);

    return sum;
}

int find(int x) {
    return root[x] == x ? x : root[x] = find(root[x]);
}

bool same(int x, int y) {
    return find(x) == find(y);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);

    if (x != y) {
        root[y] = x;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    FOR(i, 0, n) {
        root[i] = i;
        int x; cin >> x;
        arr[i] = x;
    }

    cin >> q;

    FOR(i, 0, q) {
        string ts;
        int t, x, y;
        cin >> ts >> x >> y;
        if (ts == "bridge") {
            x--; y--;
            if (!same(x, y)) {
                edge[x].push_back(y);
                edge[y].push_back(x);
                unite(x, y);
                queries[i] = {0, x, y};
            } else {
                queries[i] = {-1, x, y};
            }
        } else if (ts == "penguins") {
            x--;
            queries[i] = {1, x, y};
        } else {
            x--; y--;
            if (same(x, y))
                queries[i] = {2, x, y};
            else
                queries[i] = {3, x, y};
        }
    }

    initSeg();
    FOR(i, 0, n) {
        if (!visited[i])
            dfs(i);
    }
    memset(visited, 0, sizeof(bool) * N);
    FOR(i, 0, n) {
        if (!visited[i])
            hld(i);
    }

    FOR(i, 0, q) {
        auto& curr = queries[i];
        int type = curr.type;
        int x = curr.x;
        int y = curr.y;

        if (type == 0) {
            cout << "yes\n";
        } else if (type == -1) {
            cout << "no\n";
        } else if (type == 1) {
            update(segIndex[x], y);
        } else if (type == 2) {
            cout << query(x, y) << '\n';
        } else {
            cout << "impossible\n";
        }
    }
    
    return 0;
}