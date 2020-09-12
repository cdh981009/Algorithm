#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e3;
int n, m;

int visited[N + 1][2];
vector<pair<int, int>> edges[N + 1][2];
vector<pair<int, int>> backEdges[N + 1][2];

vector<pair<int, int>> dfsStack;
vector<int> cEdges[2 * N];
vector<pair<int, int>> c2v[2 * N];
int v2c[N + 1][2];
bool cVisited[2 * N];
int cCnt = 0;

vector<int> ans(N + 1, -1);

void dfs(int node, bool sign) {
    visited[node][sign] = 1;
    for (auto next : edges[node][sign]) {
        if (visited[next.first][next.second] != 1)
            dfs(next.first, next.second);
    }
    dfsStack.push_back({node, sign});
}

void dfsGetScc(int node, bool sign) {
    visited[node][sign] = 2;
    for (auto back : backEdges[node][sign]) {
        if (visited[back.first][back.second] != 2)
            dfsGetScc(back.first, back.second);
    }
    v2c[node][sign] = cCnt;
    c2v[cCnt].push_back({node, sign});
}

bool cDfs(int c) {
    int possible = true;

    for (auto p : c2v[c]) {
        int node = p.first;
        int sign = p.second;
        if (ans[node] == -1)
            ans[node] = sign;
        else
            possible = false;
    }

    cVisited[c] = true;
    for (auto nextC : cEdges[c]) {
        if (!cVisited[nextC])
            possible &= cDfs(nextC);
    }

    return possible;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n) {
        FOR_(i, 1, n) {
            FOR(j, 0, 2) {
                visited[i][j] = 0;
                edges[i][j].clear();
                backEdges[i][j].clear();
                v2c[i][j] = 0;
            }
            ans[i] = -1;
        }

        FOR(i, 0, 2 * n) {
            cEdges[i].clear();
            c2v[i].clear();
            cVisited[i] = false;
        }

        dfsStack.clear();
        cCnt = 0;

        cin >> m;
        FOR(i, 0, m) {
            int u, v;
            cin >> u >> v;
            int uSign = (u > 0);
            int vSign = (v > 0);
            u = abs(u);
            v = abs(v);
            edges[u][!uSign].push_back({v, vSign});
            backEdges[v][vSign].push_back({u, !uSign});
            edges[v][!vSign].push_back({u, uSign});
            backEdges[u][uSign].push_back({v, !vSign});
        }

        dfsStack.reserve(2 * n);
        FOR_(i, 1, n) {
            FOR(j, 0, 2) {
                if (visited[i][j] != 1) {
                    dfs(i, j);
                }
            }
        }

        // get strongly connected components
        FOR(i, 0, dfsStack.size()) {
            auto p = dfsStack[dfsStack.size() - 1 - i];
            auto node = p.first;
            auto sign = p.second;
            if (visited[node][sign] != 2) {
                dfsGetScc(node, sign);
                cCnt++;
            }
        }

        // connect edges between scc
        FOR_(i, 1, n) {
            FOR(j, 0, 2) {
                for (auto next : edges[i][j]) {
                    if (v2c[next.first][next.second] != v2c[i][j]) {
                        cEdges[v2c[i][j]].push_back(v2c[next.first][next.second]);
                    }
                }
            }
        }

        int possible = true;
        FOR_(i, 1, n) {
            if (v2c[i][0] == v2c[i][1]) {
                possible = false;
                break;
            }
        }

        if (possible) {
            possible = cDfs(v2c[1][true]);
        }

        cout << (possible ? "yes" : "no") << "\n";
    }

    return 0;
}