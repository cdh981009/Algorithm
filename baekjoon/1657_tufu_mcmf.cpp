// 1657: 두부장수 장홍준
// https://www.acmicpc.net/problem/1648
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 200;

constexpr int c[5][5] = {
        10, 8, 7, 5, 1,
        8, 6, 4, 3, 1,
        7, 4, 3, 2, 1,
        5, 3, 2, 2, 1,
        1, 1, 1, 1, 0};

int n, m;

struct Edge {
    int dest, cap, rev, cost;
};

int arr[N];

vector<Edge> edges[N];

int prV[N];
int prE[N];
int dist[N];
bool inQ[N];

int SRC, SINK;

void addEdge(int s, int e, int cap, int cost) {
    edges[s].push_back({e, cap, (int)edges[e].size(), cost});
    edges[e].push_back({s, 0, (int)edges[s].size() - 1, -cost});
}

bool spfa() {
    memset(prV, -1, sizeof(int) * N);
    memset(inQ, false, sizeof(bool) * N);
    FOR_(i, 0, SINK)
    dist[i] = INF;

    queue<int> q;

    q.push(SRC);
    inQ[SRC] = true;
    dist[SRC] = 0;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        inQ[v] = false;

        FOR(i, 0, edges[v].size()) {
            auto& edge = edges[v][i];
            int u = edge.dest;
            if (edge.cap > 0 && dist[u] > dist[v] + edge.cost) {
                dist[u] = dist[v] + edge.cost;
                prV[u] = v;
                prE[u] = i;
                if (!inQ[u]) {
                    q.push(u);
                    inQ[u] = true;
                }
            }
        }
    }

    return (prV[SINK] != -1);
}

// just find min cost
int mc() {
    int money = 0;
    int totalFlow = 0;

    while (spfa()) {
        int curr = SINK;
        int f = INF;
        int c = 0;
        while (curr != SRC) {
            int p = prV[curr];
            int r = edges[p][prE[curr]].cap;
            f = min(f, r);
            c += edges[p][prE[curr]].cost;
            curr = p;
        }

        // Don't care about max flow, just find min cost
        if (c > 0)
            break;

        money += f * c;
        totalFlow += f;

        curr = SINK;
        while (curr != SRC) {
            int p = prV[curr];
            edges[p][prE[curr]].cap -= f;
            edges[curr][edges[p][prE[curr]].rev].cap += f;

            curr = p;
        }
    }

    return money;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    SRC = n * m;
    SINK = n * m + 1;

    FOR(i, 0, n * m) {
        char c;
        cin >> c;
        arr[i] = (c == 'F' ? 4 : c - 'A');
    }

    FOR(x, 0, m) {
        FOR(y, 0, n) {
            int pos = y * m + x;
            if ((x + y) % 2 == 0) {
                addEdge(SRC, pos, 1, 0);
                if (x - 1 >= 0) {
                    addEdge(pos, pos - 1, 1, -c[arr[pos]][arr[pos - 1]]);
                }
                if (x + 1 < m) {
                    addEdge(pos, pos + 1, 1, -c[arr[pos]][arr[pos + 1]]);
                }
                if (y - 1 >= 0) {
                    addEdge(pos, pos - m, 1, -c[arr[pos]][arr[pos - m]]);
                }
                if (y + 1 < n) {
                    addEdge(pos, pos + m, 1, -c[arr[pos]][arr[pos + m]]);
                }
            } else {
                addEdge(pos, SINK, 1, 0);
            }
        }
    }

    cout << -mc() << '\n';

    return 0;
}