// 11400: 단절선
// https://www.acmicpc.net/problem/11400
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 101010;

vector<int> edges[N];
int backEdgeMinDepth[N];
int depth[N];
int visited[N];
int v, e;

vector<pair<int, int>> cutEdges;

void dfs(int node, int par) {
    backEdgeMinDepth[node] = INF;
    visited[node] = true;
    depth[node] = depth[par] + 1;

    FOR(i, 0, edges[node].size()) {
        int adj = edges[node][i];
        if (adj == par)
            continue;
        
        if (visited[adj]) {
            // back edge
            backEdgeMinDepth[node] = min(backEdgeMinDepth[node], depth[adj]);
        } else {
            dfs(adj, node);
            backEdgeMinDepth[node] = min(backEdgeMinDepth[node], backEdgeMinDepth[adj]);
            // if this edge is not a back edge
            // and it's subtree doesn't have any back edges
            // to my ancestors, it is a cut edge
            if (backEdgeMinDepth[adj] > depth[node]) {
                int x = node;
                int y = adj;
                if (x > y)
                    swap(x, y);
                cutEdges.push_back({x, y});
            }
        }
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

    dfs(1, 0);

    sort(cutEdges.begin(), cutEdges.end());

    cout << cutEdges.size() << '\n';
    FOR(i, 0, cutEdges.size()) {
        auto &e = cutEdges[i];
        cout << e.first << ' ' << e.second << '\n';
    }

    return 0;
}