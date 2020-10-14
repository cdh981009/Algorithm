// 11378: 열혈강호 4
// https://www.acmicpc.net/problem/11378
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1000;

int n, m, k;
int cap[2 * N + 3][2 * N + 3];
int flow[2 * N + 3][2 * N + 3];

vector<int> adj[2 * N + 3];

bool visited[2 * N + 3];
int parent[2 * N + 3];

int SRC;
int PENALTY;
int SINK;

int fordFulkerson() {
    int totalFlow = 0;

    while (true) {
        memset(visited, false, sizeof(bool) * (2 * N + 3));
        memset(parent, -1, sizeof(int) * (2 * N + 3));
        
        queue<int> qu;
        qu.push(SRC); // source;
        parent[SRC] = SRC;
        visited[SRC] = true;

        // BFS
        while (!qu.empty()) {
            int curr = qu.front();
            qu.pop();

            if (curr == SINK) { // sink
                break;
            }

            for (auto i : adj[curr]) {
                if (!visited[i] && cap[curr][i] - flow[curr][i] > 0) { // not saturated
                    visited[i] = true;
                    parent[i] = curr;
                    qu.push(i);
                }
            }
        }

        if (parent[SINK] == -1) { // can't find path
            break;
        }

        int curr;
        int minFlow;

        // back track, find bottleneck edge
        curr = SINK;
        minFlow = INF;
        while (curr != SRC) {
            int p = parent[curr];
            int r = cap[p][curr] - flow[p][curr];
            minFlow = min(minFlow, r);
            curr = p;
        }

        // spill the flow
        curr = SINK;
        while (curr != SRC) {
            int p = parent[curr];
            flow[p][curr] += minFlow;
            flow[curr][p] -= minFlow;
            curr = p;
        }
        totalFlow += minFlow;
    }

    return totalFlow;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;

    SRC     = n + m;
    PENALTY = n + m + 1;
    SINK    = n + m + 2;

    auto addEdge = [](int a, int b, int c) {
        cap[a][b] = c;
        adj[a].push_back(b);
        adj[b].push_back(a);
    };

    addEdge(SRC, PENALTY, k);

    FOR(i, 0, n) {
        addEdge(SRC, i, 1);
        addEdge(PENALTY, i, k);

        int c;
        cin >> c;
        FOR(j, 0, c) {
            int work;
            cin >> work;
            work--;
            addEdge(i, n + work, 1);
        }
    }

    FOR(i, 0, m) {
        addEdge(n + i, SINK, 1);
    }

    cout << fordFulkerson() << endl;
    return 0;
}