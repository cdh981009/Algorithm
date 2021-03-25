#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e5;
int n, m;
vector<int> edges[N];
vector<int> backEdges[N];
bool visited[N];

vector<int> stk;
int scc[N];

int componentCnt;
bool doesComponentHavePredecessor[N];

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

        FOR(i, 0, n) {
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

        FOR(i, 0, n) {
            if (!visited[i]) {
                dfs1(i);
            }
        }

        FOR(i, 0, n) {
            visited[i] = false;
        }
        componentCnt = 0;

        FOR(i, 0, stk.size()) {
            auto node = stk[stk.size() - 1 - i];
            if (!visited[node]) {
                dfs2(node);
                componentCnt++;
            }
        }

        int startingPointCnt = componentCnt;
        FOR(i, 0, n) {
            for (auto next : edges[i]) {
                if (scc[i] == scc[next])
                    continue;
                if (!doesComponentHavePredecessor[scc[next]]) {
                    startingPointCnt--;
                    doesComponentHavePredecessor[scc[next]] = true;
                }
            }
        }
        if (startingPointCnt > 1) {
            cout << "Confused" << "\n";
        } else {
            int startingPoint;
            FOR(i, 0, componentCnt) {
                if (!doesComponentHavePredecessor[i]) {
                    startingPoint = i;
                    break;
                }
            }
            FOR(i, 0, n) {
                if (scc[i] == startingPoint)
                    cout << i << "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}