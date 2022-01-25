#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;

constexpr int N = 2e5;
int n, m;
vector<int> edges[N];
int stat[N];

bool contains(int u, int v) {
    auto it = lower_bound(edges[u].begin(), edges[u].end(), v);
    return (it != edges[u].end() && *it == v);
}

void dfs(int node, int p) {
    for(auto &x : edges[node]) {
        if (x == p)
            continue;
        
        if (stat[x] == 0) {
            stat[x] = 1;
            dfs(x, node);
        } else if (stat[x] == 1) {
            stat[x] = 3;
        }
        
        if (!contains(x, node))
            stat[x] = 3;
    }

    if (stat[node] == 1)
        stat[node] = 2;
}

void dfs2(int node, int p) {
    stat[node] = 4;

    for(auto &x : edges[node]) {
        if (x == p)
            continue;
        if (stat[x] == 4)
            continue;
        
        dfs2(x, node);
    }
}   

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    FOR(i, 0, m) {
        int u, v; cin >> u >> v;
        u--, v--;
        edges[u].push_back(v);
    }

    FOR(i, 0, n)
        sort(edges[i].begin(), edges[i].end());

    FOR(i, 0, n) {
        if (stat[i] == 0) {
            stat[i] = 1;
            dfs(i, -1);
        }
    }

    FOR(i, 0, n) {
        if (stat[i] == 3) {
            dfs2(i, -1);
        }
    }

    //FOR(i, 0, n)
    //   cout << i << ' ' << stat[i] << '\n';

    bool p = true;
    FOR(i, 0, n) {
        if (stat[i] != 4) {
            p = false;
            break;
        }
    }

    cout << (p ? "YES" : "NO") << '\n';

    return 0;
}