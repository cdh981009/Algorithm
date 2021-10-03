#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 101010;

bool ans;
int arr[N];
int xr[N];
vector<int> edges[N];
int n, m, y;

void dfs(int node, int par, int t) {
    int& x = xr[node];
    x = arr[node];
    FOR(i, 0, edges[node].size()) {
        int c = edges[node][i];
        if (c == par)
            continue;
        dfs(c, node, t);
        if (xr[c] != t)
            x ^= xr[c];
    }

    if (x == t)
        y++;
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
        cin >> n >> m;
        int x = 0;
        FOR(i, 0, n) {
            cin >> arr[i];
            x ^= arr[i];
        }
        FOR(i, 0, n) {
            edges[i].clear();
        }
        FOR(i, 0, n - 1) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        ans = false;
        if (x == 0) {
            // even num of components
            ans = true;
        } else {
            // odd num -> 3
            if (m >= 3) {
                y = 0;
                dfs(0, -1, x);
                if (y >= 3)
                    ans = true;
            }
        }


        cout << (ans ? "YES" : "NO") << '\n';
    }
    return 0;
}