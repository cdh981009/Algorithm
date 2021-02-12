// 11266: 단절점
// https://www.acmicpc.net/problem/11266
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 10101;

vector<int> edges[N];
int backEdgeMinDepth[N];
int depth[N];
int visited[N];
int v, e;

vector<int> cutVertices;

void dfs(int node, int par) {
    backEdgeMinDepth[node] = INF;
    visited[node] = true;
    depth[node] = depth[par] + 1;

    int children = 0;
    bool cutVertex = false;

    FOR(i, 0, edges[node].size()) {
        int adj = edges[node][i];
        if (adj == par)
            continue;

        if (visited[adj]) {
            // back edge
            backEdgeMinDepth[node] = min(backEdgeMinDepth[node], depth[adj]);
        } else {
            children++;
            dfs(adj, node);
            backEdgeMinDepth[node] = min(backEdgeMinDepth[node], backEdgeMinDepth[adj]);

            if (backEdgeMinDepth[adj] >= depth[node]) {
                cutVertex = true;
            }
        }
    }

    if ((depth[node] == 1 && children > 1) || (depth[node] > 1 && cutVertex)) {
        cutVertices.push_back(node);
    }
    //cout << node << ": " << backEdgeMinDepth[node] << '\n';
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> v >> e;
    FOR(i, 0, e) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    FOR_(i, 1, v) {
        if (!visited[i])
            dfs(i, 0);
    }

    sort(cutVertices.begin(), cutVertices.end());

    cout << cutVertices.size() << '\n';
    FOR(i, 0, cutVertices.size()) {
        cout << cutVertices[i] << ' ';
    }
    cout << '\n';

    return 0;
}