#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 1e5;

int ans;
vector<pii> edges[N];
int e[N];

int n;

void dfs(int node, int p, int prev) {
    if (p == -1) {
        if (edges[node].size() == 2) {
            e[edges[node][0].second] = 2;
            e[edges[node][1].second] = 5;
            dfs(edges[node][0].first, node, 2);
            dfs(edges[node][1].first, node, 5);
        } else {
            e[edges[node][0].second] = 2;
            dfs(edges[node][0].first, node, 2);
        }
    } else {
        FOR(i, 0, edges[node].size()) {
            if (edges[node][i].first == p) continue;
            int w = prev == 2 ? 5 : 2;
            e[edges[node][i].second] = w;
            dfs(edges[node][i].first, node, w);
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n;

        bool pos = true;

        FOR(i, 0, n) {
            edges[i].clear();
        }
        
        FOR(i, 0, n - 1) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            edges[u].push_back({v, i});
            edges[v].push_back({u, i});
            if (edges[u].size() > 2 || edges[v].size() > 2)
                pos = false;
        }

        if (!pos) {
            cout << -1 << '\n';
        } else {
            dfs(0, -1, 0);
            FOR(i, 0, n - 1) {
                cout << e[i] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}