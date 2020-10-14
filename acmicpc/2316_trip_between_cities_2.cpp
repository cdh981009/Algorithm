// 2316: 도시 왕복하기 2
// https://www.acmicpc.net/problem/2316
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 400;
int n, p;

int cap[2 * N][2 * N];
int flow[2 * N][2 * N];
bool visited[2 * N];
int parent[2 * N];

int SRC;
int SINK;

int fordFulkerson() {
    int totalFlow = 0;

    while (true) {
        memset(visited, false, sizeof(bool) * 2 * n);
        memset(parent, -1, sizeof(int) * 2 * n);
        
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

            FOR(i, 0, 2 * n) {
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

    cin >> n >> p;

    SRC = 0 + n;
    SINK = 1;

    FOR(i, 0, n) {
        cap[i][i + n] = 1;
    }

    FOR(i, 0, p) {
        int s, d; cin >> s >> d;
        s--;
        d--;
        cap[s + n][d] = 1;
        cap[d + n][s] = 1;
    }

    cout << fordFulkerson() << endl;
    return 0;
}