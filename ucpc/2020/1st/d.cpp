#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 501010;
vector<int> edges[N];
int sub[N][3];
int parent[N];
long long d, g;

void dfs(int node, int par) {
    parent[node] = par;
    FOR(i, 0, edges[node].size()) {
        int child = edges[node][i];
        if (child == par)
            continue;
        sub[node][0]++;

        dfs(child, node);
        sub[node][1] += sub[child][0];
        sub[node][2] += sub[child][1];
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    FOR(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    dfs(0, -1);

    d = 0;
    g = 0;
    FOR(i, 0, n) {
        int node = i;
        // count d
        FOR(j, 0, edges[node].size()) {
            int child = edges[node][j];
            if (parent[node] == child)
                continue;
            d += (sub[node][1] - sub[child][0]);
        }
        d += sub[node][2];

        // count g
        int x = sub[node][0];
        if (parent[node] != -1) {
            g += (long long)x * (x - 1) / 2;
        }
        g += (long long)x * (x - 1) * (x - 2) / 6;
    }

    // cout << d << ' ' << g << endl;

    if (d > g * 3) {
        cout << "D";
    } else if (d < g * 3) {
        cout << "G";
    } else {
        cout << "DUDUDUNGA";
    }
    cout << '\n';

    return 0;
}