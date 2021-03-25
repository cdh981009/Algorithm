#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e5;
constexpr int logN = 16;
int sparseAncestor[N + 1][logN + 1];
int minCost[N + 1][logN + 1];
int maxCost[N + 1][logN + 1];
vector<pair<int, int>> edge[N + 1];
int depth[N + 1];

void dfs(int node) {
    for (auto p : edge[node]) {
        int child = p.first;
        int cost = p.second;
        if (sparseAncestor[node][0] == child)
            continue;
        sparseAncestor[child][0] = node;
        minCost[child][0] = cost;
        maxCost[child][0] = cost;
        depth[child] = depth[node] + 1;
        dfs(child);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    FOR(i, 0, n - 1) {
        int u, v, c;
        cin >> u >> v >> c;
        edge[u].push_back({v, c});
        edge[v].push_back({u, c});
    }
    //depth[1] = 1;
    dfs(1);
    FOR_(i, 1, logN) {
        FOR_(j, 1, n) {
            int m = sparseAncestor[j][i - 1];
            int minC = minCost[j][i - 1];
            int maxC = maxCost[j][i - 1];
            sparseAncestor[j][i] = sparseAncestor[m][i - 1];
            minCost[j][i] = min(minC, minCost[m][i - 1]);
            maxCost[j][i] = max(maxC, maxCost[m][i - 1]);
        }
    }
    int m;
    cin >> m;
    FOR(i, 0, m) {
        int lca;
        int u, v;
        int uMin, uMax;
        int vMin, vMax;
        uMin = vMin = INF;
        uMax = vMax = 0;

        cin >> u >> v;
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
            vMin = min(vMin, minCost[v][cnt]);
            vMax = max(vMax, maxCost[v][cnt]);
            v = sparseAncestor[v][cnt];
        }
        // now depth is same
        // cout << "depth is same " << u << " " << v << endl;
        int minVal, maxVal;
        if (u == v) {
            minVal = vMin;
            maxVal = vMax;
        } else {
            int step = logN;
            for (int step = logN; step >= 0; step -= 2) {
                // binary searching lca, keeping min and max values to the lca.
                while (sparseAncestor[v][step] != sparseAncestor[u][step]) {
                    vMin = min(vMin, minCost[v][step]);
                    vMax = max(vMax, maxCost[v][step]);
                    uMin = min(uMin, minCost[u][step]);
                    uMax = max(uMax, maxCost[u][step]);
                    v = sparseAncestor[v][step];
                    u = sparseAncestor[u][step];
                }
            }
            vMin = min(vMin, minCost[v][0]);
            vMax = max(vMax, maxCost[v][0]);
            uMin = min(uMin, minCost[u][0]);
            uMax = max(uMax, maxCost[u][0]);
            minVal = min(vMin, uMin);
            maxVal = max(vMax, uMax);
        }

        cout << minVal << " " << maxVal << "\n";
    }
    return 0;
}