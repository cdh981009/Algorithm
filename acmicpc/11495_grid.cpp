// 11495: Grid
// https://www.acmicpc.net/problem/11495
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 50;
constexpr int V = N * N + 2;

// Dinic: O(EV^2)

int n, m;

int flow[V][V];
vector<int> edge[V];
int level[V];
int cache[V];
int arr[N][N];

const int SRC = V - 2;
const int SINK = V - 1;

// dinic's algorithm
// generate level graph
bool bfs() {
    memset(level, -1, sizeof(int) * V);

    queue<int> q;
    q.push(SRC);
    level[SRC] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == SINK)
            break;

        for (auto next : edge[curr]) {
            if (level[next] == -1 && flow[curr][next] > 0) {
                level[next] = level[curr] + 1;
                q.push(next);
            }
        }
    }

    if (level[SINK] == -1)
        return false;
    return true;
}

// augment graph with blocking flow
int dfs(int curr, int cap) {
    if (curr == SINK) {
        return cap;
    }

    for (int i = cache[curr]; i < edge[curr].size(); ++i) {
        cache[curr] = i;
        int next = edge[curr][i];

        if (level[next] == level[curr] + 1 && flow[curr][next] > 0) {
            int c = dfs(next, min(cap, flow[curr][next]));
            if (c > 0) {
                flow[curr][next] -= c;
                flow[next][curr] += c;
                return c;
            }
        }
    }

    return 0;
}

int dinic() {
    int totalFlow = 0;
    while (bfs()) {
        memset(cache, 0, sizeof(int) * V);
        int d;
        while (d = dfs(SRC, INF))
            totalFlow += d;
    }
    return totalFlow;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    auto addEdge = [](int a, int b, int c) {
        flow[a][b] = c;
        edge[a].push_back(b);
        edge[b].push_back(a);
    };

    while (tc--) {
        cin >> n >> m;

        memset(flow, 0, sizeof(int) * V * V);

        FOR(i, 0, n) {
            FOR(j, 0, m) {
                cin >> arr[i][j];
            }
        }

        // init graph
        FOR(i, 0, n) {
            FOR(j, 0, m) {
                if ((i + j) % 2 == 0) {
                    addEdge(SRC, i * m + j, arr[i][j]);
                    if (j + 1 < m) {
                        addEdge(i * m + j, i * m + j + 1, arr[i][j]);
                    }
                    if (j - 1 >= 0) {
                        addEdge(i * m + j, i * m + j - 1, arr[i][j]);
                    }
                    if (i + 1 < n) {
                        addEdge(i * m + j, (i + 1) * m + j, arr[i][j]);
                    }
                    if (i - 1 >= 0) {
                        addEdge(i * m + j, (i - 1) * m + j, arr[i][j]);
                    }
                } else {
                    addEdge(i * m + j, SINK, arr[i][j]);
                }
            }
        }

        int x = dinic();
        // clean remaining
        // init graph
        FOR(i, 0, n) {
            FOR(j, 0, m) {
                if ((i + j) % 2 == 0) {
                    x += flow[SRC][i * m + j];
                } else {
                    x += flow[i * m + j][SINK];
                }
            }
        }

        cout << x << '\n';
    }

    return 0;
}