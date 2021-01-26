// 11409: 열혈강호6
// https://www.acmicpc.net/problem/11409
#include <bits/stdc++.h>

using namespace std;

#define INF (4e6 + 1)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

// Max-cost Max-flow
// O(f * E)
// Ford-Fulkerson + SPFA

constexpr int N = 802;

int n, m;
vector<int> edges[N];
int cost[N][N];
int flow[N][N];
int cap[N][N];
int prv[N];
int dist[N];
bool inQ[N];

int SRC, SINK;

void addEdge(int s, int e, int c) {
    cap[s][e] = 1;
    edges[s].push_back(e);
    edges[e].push_back(s);
    cost[s][e] = +c;
    cost[e][s] = -c;
}

bool spfa() {
    memset(prv, -1, sizeof(int) * N);
    memset(dist, -1, sizeof(int) * N);
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
                    (dist[u] == -1 ? INF : dist[u]) > dist[v] + cost[v][u]) {
                dist[u] = dist[v] + cost[v][u];
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

pair<int, int> mcmf() {
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
            c += cost[p][curr];

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

    return {totalFlow, money};
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    SRC = n + m;
    SINK = n + m + 1;

    FOR(i, 0, n) {
        addEdge(SRC, i, 0);

        int x;
        cin >> x;
        FOR(j, 0, x) {
            int w, c;
            cin >> w >> c;
            w--;
            w += n;
            addEdge(i, w, -c);
        }
    }

    FOR(i, 0, m) {
        addEdge(i + n, SINK, 0);
    }

    auto res = mcmf();

    cout << res.first << '\n' << -res.second << '\n';

    return 0;
}