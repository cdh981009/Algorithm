#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e5;
int n, m;
vector<int> edges[N + 1];
vector<int> backEdges[N + 1];
bool visited[N + 1];

vector<int> stk;
int scc[N + 1];

int componentCnt;
bool doesComponentHavePredecessor[N + 1];

void dfs1(int node) {
    visited[node] = true;
    for (auto next : edges[node]) {
        if (!visited[next])
            dfs1(next);
    }
    stk.push_back(node);
}

void dfs2(int node) {
    visited[node] = true;
    for (auto parent : backEdges[node]) {
        if (!visited[parent])
            dfs2(parent);
    }
    scc[node] = componentCnt;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> m;

        FOR_(i, 1, n) {
            edges[i].clear();
            backEdges[i].clear();
            visited[i] = false;
            doesComponentHavePredecessor[i] = false;
            scc[i] = 0;
        }
        stk.clear();

        FOR(i, 0, m) {
            int u, v;
            cin >> u >> v;
            edges[u].push_back(v);
            backEdges[v].push_back(u);
        }

        FOR_(i, 1, n) {
            if (!visited[i]) {
                dfs1(i);
            }
        }

        FOR_(i, 1, n) {
            visited[i] = false;
        }
        componentCnt = 0;

        FOR(i, 0, stk.size()) {
            auto node = stk[stk.size() - 1 - i];
            if (!visited[node]) {
                componentCnt++;
                dfs2(node);
            }
        }

        int ans = componentCnt;
        FOR_(i, 1, n) {
            for (auto next : edges[i]) {
                if (scc[i] == scc[next]) continue;
                if (!doesComponentHavePredecessor[scc[next]]) {
                    ans--;
                    doesComponentHavePredecessor[scc[next]] = true;
                }
            }
        }
        
        cout << ans << "\n";
    }
    return 0;
}