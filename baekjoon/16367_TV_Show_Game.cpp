#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 5e3;
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

void cDfs(int c) {
    cVisited[c] = true;
    for (auto nextC : cEdges[c]) {
        if (!cVisited[nextC])
            cDfs(nextC);
    }
    for (auto p : c2v[c]) {
        int node = p.first;
        int sign = p.second;
        if (ans[node] == -1)
            ans[node] = sign;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    FOR(i, 0, m) {
        pair<int, bool> guess[3];
        FOR(j, 0, 3) {
            int num; cin >> num;
            char color; cin >> color;
            guess[j] = {num, color == 'R'};
            FOR(k, 0, j) {
                int u = guess[k].first;
                int uSign = guess[k].second;
                int v = guess[j].first;
                int vSign = guess[j].second;

                edges[u][!uSign].push_back({v, vSign});
                backEdges[v][vSign].push_back({u, !uSign});
                edges[v][!vSign].push_back({u, uSign});
                backEdges[u][uSign].push_back({v, !vSign});
            }
        }
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
        FOR(i, 0, cCnt) {
            if (!cVisited[i]) {
                cDfs(i);
            }
        }

        FOR_(i, 1, n) {
            cout << (ans[i] ? 'R' : 'B');
        }
        cout << "\n";
    } else {
        cout << -1 << "\n";
    }

    return 0;
}