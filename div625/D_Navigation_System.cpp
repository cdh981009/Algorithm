#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int node, edges; cin >> node >> edges;
    vector<vector<int>> inverse(node + 1, vector<int>());
    FOR(i, 0, edges) {
        int src, dst; cin >> src >> dst;
        inverse[dst].push_back(src);
    }

    int intersec; cin >> intersec;
    vector<int> path(intersec);
    FOR(i, 0, intersec) {
        int n; cin >> n;
        path[i] = n;
    }

    int dest = path.back();
    queue<int> que;
    vector<int> visit(node + 1, 0);
    vector<vector<int>> next(node + 1);

    next[dest].push_back(dest);
    que.push(dest);
    while (!que.empty()) {
        int dst = que.front(); que.pop();
        // cout << "dst " << dst << "\n";
        for (auto src : inverse[dst]) {
            if (next[src].empty()) {
                que.push(src);
                visit[src] = visit[dst] + 1;
            }
            // cout << "visiting " << src << " " << visit[src] << "\n";
            if (visit[src] == visit[dst] + 1) {
                next[src].push_back(dst);
            }
        }
    }

    int minBuild, maxBuild;
    minBuild = maxBuild = 0;
    FOR(i, 1, path.size()) {
        int curr = path[i];
        int prev = path[i-1];
        bool isInShortestPath = find(next[prev].begin(), next[prev].end(), curr) != next[prev].end();
        if (isInShortestPath) {
            maxBuild += (next[prev].size() > 1);
        } else {
            maxBuild++;
            minBuild++;
        }
    }

    cout << minBuild << " " << maxBuild << "\n";
    return 0;
}