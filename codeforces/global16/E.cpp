#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 201010;

int n;
int ans;
vector<int> edges[N];
int par[N];
bool bud[N];

void dfs(int node, int par) {
    int cnt = 0;
    FOR(i, 0, edges[node].size()) {
        int c = edges[node][i];
        if (c == par)
            continue;
        cnt++;
        dfs(c, node);
        if (bud[c])
            cnt--;
    }

    if (cnt == 0) {
        bud[node] = false;
        ans++;
    } else if (node != 0) {
        bud[node] = true;
        ans--;
    }

    if (node == 0) {
        if (bud[node])
            ans++;
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
        memset(edges, 0, sizeof(vector<int>) * n);
        FOR(i, 0, n - 1) {
            int u, v; cin >> u >> v;
            u--, v--;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        ans = 0;
        dfs(0, -1);
        
        cout << ans << '\n';
    }
    return 0;
}