#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 201010;

int n;
int h[N];
vector<int> edges[N];
ll ans;

// root is i of maximum h[i];
int dfs(int node, int par) {
    bool leaf = true;
    
    int m[2] = { 0, 0 };

    auto up = [&](int x) {
        if (x >= m[0]) {
            m[1] = m[0];
            m[0] = x;
        } else if (x > m[1]) {
            m[1] = x;
        }
    };

    for (auto &c : edges[node]) {
        if (c == par) continue;
        leaf = false;
        up(dfs(c, node));
    }
    // cout << node << ' ' << m[0] << ' ' << m[1] << '\n';

    if (par == -1) { // root
        ans += h[node] - m[0];
        ans += h[node] - m[1];
    } else if (!leaf) {
        // pick maximum node in subtree
        // set eff accordingly
        if (m[0] < h[node]) {
            ans += h[node] - m[0];
            m[0] = h[node];
        }
    } else {
        ans += h[node];
        return h[node];
    }

    return m[0];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    int rt = 0;
    int mx = 0;
    FOR_(i, 1, n) {
        cin >> h[i];
        if (h[i] > mx) {
            mx = h[i];
            rt = i;
        }
    }

    // cout << rt << '\n';

    FOR(i, 0, n-1) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    dfs(rt, -1);

    cout << ans << '\n';

    return 0;
}