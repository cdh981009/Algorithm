#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e5;
constexpr int logN = 16; 
int sparseAncestor[N + 1][logN + 1];
vector<int> edge[N + 1];
int depth[N + 1];

void dfs(int node) {
    for (auto child : edge[node]) {
        if (sparseAncestor[node][0] == child) continue;
        sparseAncestor[child][0] = node;
        depth[child] = depth[node] + 1;
        dfs(child);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    FOR(i, 0, n - 1) {
        int u, v; cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    //depth[1] = 1;
    dfs(1);
    FOR_(i, 1, logN) {
        FOR_(j, 1, n) {
            int m = sparseAncestor[j][i - 1];
            sparseAncestor[j][i] = sparseAncestor[m][i - 1];
        }
    }
    int m; cin >> m;
    FOR(i, 0, m) {
        int ans;
        int u, v; cin >> u >> v;
        if (depth[u] > depth[v]) {
            swap(u, v);
        }
        while (depth[u] < depth[v]) {
            int diff = depth[v] - depth[u];
            int cnt = 0;
            int num = 1;
            while (num * 2 <= diff) {
                num *= 2;
                cnt++;
            }
            v = sparseAncestor[v][cnt];
        }
        // now depth is same
        // cout << "depth is same " << u << " " << v << endl;
        if (u == v) {
            ans = u;
        } else {
            int step = logN;
            for (int step = logN; step >= 0; step -= 1) {
                while (sparseAncestor[v][step] != sparseAncestor[u][step]) {
                    v = sparseAncestor[v][step];
                    u = sparseAncestor[u][step];
                }
            }
            ans = sparseAncestor[v][0];
        }

        cout << ans << "\n";
    }
    return 0;
}