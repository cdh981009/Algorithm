// 11493: Coin Swap
// https://www.acmicpc.net/problem/11409
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

// Min-cost Max-flow
// O(f * E)
// Ford-Fulkerson + SPFA

constexpr int N = 502;

int n, m;
vector<int> edges[N];

int cost[N][N];
int flow[N][N];
int cap[N][N];

int prv[N];
int dist[N];
bool inQ[N];

int SRC, SINK;

void addEdge(int s, int e, int c, int w) {
    cap[s][e] = c;
    edges[s].push_back(e);
    edges[e].push_back(s);
    cost[s][e] = w;
    cost[e][s] = -w;
}

void addUndirectedEdge(int s, int e, int c, int w) {
    cap[s][e] = c;
    cap[e][s] = c;
    edges[s].push_back(e);
    edges[e].push_back(s);
    cost[s][e] = w;
    cost[e][s] = w;
}

bool spfa() {
    memset(prv, -1, sizeof(int) * N);
    FOR_(i, 0, SINK) {
        dist[i] = INF;
    }
    memset(inQ, false, sizeof(bool) * N);

    queue<int> q;

    q.push(SRC);
    inQ[SRC] = true;
    dist[SRC] = 0;

    while (!q.empty()) {
        int v = q.front();
        inQ[v] = false;
        q.pop();

        FOR(i, 0, edges[v].size()) {
            int u = edges[v][i];
            if (cap[v][u] - flow[v][u] > 0 &&
                    dist[u] > dist[v] + (flow[v][u] >= 0 ? 1 : -1) * cost[v][u]) {
                dist[u] = dist[v] + (flow[v][u] >= 0 ? 1 : -1) * cost[v][u];
                prv[u] = v;
                if (!inQ[u]) {
                    q.push(u);
                    inQ[u] = true;
                }
            }
        }
    }

    return (prv[SINK] != -1);
}

int mcmf() {
    int money = 0;
    int totalFlow = 0;

    while (spfa()) {
        int curr = SINK;
        int f = INF;
        int c = 0;
        while (curr != SRC) {
            int p = prv[curr];
            int r = cap[p][curr] - flow[p][curr];
            f = min(f, r);

            // 상쇄하는 flow면 cost가 음수
            c += (flow[p][curr] >= 0 ? 1 : -1) * cost[p][curr];

            curr = p;
        }

        money += f * c;
        totalFlow += f;

        curr = SINK;
        while (curr != SRC) {
            int p = prv[curr];
            flow[p][curr] += f;
            flow[curr][p] -= f;

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

    int tc;
    cin >> tc;

    while (tc--) {
        memset(edges, 0, sizeof(vector<int>) * N);
        memset(cap, 0, sizeof(int) * N * N);
        memset(cost, 0, sizeof(int) * N * N);
        memset(flow, 0, sizeof(int) * N * N);

        cin >> n >> m;

        SRC = n;
        SINK = n + 1;

        FOR(i, 0, m) {
            int s, e;
            cin >> s >> e;
            s--;
            e--;
            addUndirectedEdge(s, e, n, 1);
        }

        FOR(i, 0, n) {
            bool s;
            cin >> s;
            if (s)
                addEdge(SRC, i, 1, 0);
        }

        FOR(i, 0, n) {
            bool s;
            cin >> s;
            if (s)
                addEdge(i, SINK, 1, 0);
        }

        cout << mcmf() << '\n';
    }
    return 0;
}