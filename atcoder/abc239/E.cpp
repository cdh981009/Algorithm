#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 101010;

int n, q;
int x[N];
vector<int> edges[N];
vector<int> nodes[N];

void dfs(int node, int p) {
    auto &v = nodes[node];
    v.push_back(x[node]);
    for (auto &c: edges[node]) {
        if (c == p) continue;
        dfs(c, node);
        for (auto &x : nodes[c]) {
            v.push_back(x);
        }
    }
    sort(v.rbegin(), v.rend());
    if (v.size() > 20) v.resize(20);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    FOR(i, 0, n) cin >> x[i + 1];
    FOR(i, 0, n - 1) { 
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    dfs(1, 0);

    FOR(i, 0, q) {
        int v, k; cin >> v >> k;
        cout << nodes[v][k - 1] << '\n';
    }
    return 0;
}