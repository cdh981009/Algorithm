#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 5e4;
int root[N];
int sz[N];
int visited[N];
vector<int> edge[N];

int find(int x) {
    if (root[x] == x)
        return x;
    return root[x] = find(root[x]);
}

bool same(int x, int y) {
    return find(x) == find(y);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y)
        return;

    if (sz[x] < sz[y])
        swap(x, y);

    root[y] = x;
    sz[x] += sz[y];
}

int size(int x) {
    return sz[find(x)];
}

bool dfs(int node) {
    visited[node] = 1;

    bool ret = true;
    for (auto child : edge[node]) {
        if (visited[find(child)] == 1)
            return false;
        else if (visited[find(child)] == 0)
            ret &= dfs(find(child));
    }

    visited[node] = 2;
    return ret;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    FOR(i, 0, N) {
        root[i] = i;
        sz[i] = 0;
        visited[i] = 0;
    }

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> matches;
    FOR(i, 0, m) {
        int x, y;
        char r;
        cin >> x >> r >> y;
        if (r == '=')
            unite(x, y);
        else
            matches.push_back({x, y});
    }
    for (auto match : matches) {
        int x = match.first;
        int y = match.second;
        edge[find(x)].push_back(find(y));
    }

    bool ans = true;
    FOR(i, 0, n) {
        if (visited[find(i)] == 0)
            ans &= dfs(find(i));
    }
    cout << (ans ? "consistent" : "inconsistent") << "\n";

    return 0;
}