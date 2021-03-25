#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

bool dfs(int node, vector<int>& visited, vector<int>& stck, const vector<vector<bool>>& edge) {
    visited[node] = 0;
    bool possible = true;
    FOR(next, 1, edge[node].size()) {
        if (!edge[node][next])
            continue;
        if (visited[next] == -1)
            possible &= dfs(next, visited, stck, edge);
        else if (visited[next] == 0)
            return false;
    }
    visited[node] = 1;
    stck.push_back(node);
    return possible;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<bool>> edge(n + 1, vector<bool>(n + 1, false));
        vector<int> oldRank(n + 1);
        FOR(i, 0, n) {
            int x;
            cin >> x;
            oldRank[x] = i;
        }
        FOR_(i, 1, n) {
            FOR_(j, 1, n) {
                if (oldRank[i] < oldRank[j])
                    edge[i][j] = true;
                //cout << edge[i][j] << " ";
            }
            //cout << "\n";
        }
        int m;
        cin >> m;
        FOR(i, 0, m) {
            int a, b;
            cin >> a >> b;
            swap(edge[a][b], edge[b][a]);
        }
        vector<int> visited(n + 1, -1);
        vector<int> stck;
        bool possible = true;
        FOR_(i, 1, n) {
            if (visited[i] == -1) {
                if(!dfs(i, visited, stck, edge)) {
                    possible = false;
                    break;
                }
            }
        }
        if (possible) {
            for (auto i = stck.rbegin(); i != stck.rend(); ++i) {
                cout << *i << " ";
            }
            cout << "\n";
        } else {
            cout << "IMPOSSIBLE" << "\n";
        }
    }

    return 0;
}