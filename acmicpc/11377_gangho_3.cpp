// 11377: 열혈강호3
// https://www.acmicpc.net/problem/11377
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 2010;

int n, m, k;
int flow[N][N];
int level[N];

vector<int> adj[N];

bool visited[N];
int cache[N];

int SRC = N - 1;
int SNK = N - 2;
int AUX = N - 3;

// dinic's algorithm
// generate level graph
bool bfs() {
    memset(level, -1, sizeof(int) * N);

    queue<int> q;
    q.push(SRC);
    level[SRC] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == SNK)
            break;

        for (auto next : adj[curr]) {
            if (level[next] == -1 && flow[curr][next] > 0) {
                level[next] = level[curr] + 1;
                q.push(next);
            }
        }
    }

    if (level[SNK] == -1)
        return false;
    return true;
}

// augment graph with blocking flow
int dfs(int curr, int cap) {
    if (curr == SNK) {
        return cap;
    }

    for (int i = cache[curr]; i < adj[curr].size(); ++i) {
        cache[curr] = i;
        int next = adj[curr][i];

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
        memset(cache, 0, sizeof(int) * N);
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

    auto addEdge = [](int a, int b, int c) {
        adj[a].push_back(b);
        adj[b].push_back(a);
        flow[a][b] = c;
    };

    cin >> n >> m >> k;
    FOR(i, 0, n) {
        addEdge(SRC, i, 1);
        addEdge(AUX, i, 1);
        int num;
        cin >> num;
        FOR(j, 0, num) {
            int w;
            cin >> w;
            w--;
            addEdge(i, w + n, 1);
        }
    }

    FOR(i, 0, m) {
        addEdge(i + n, SNK, 1);
    }

    addEdge(SRC, AUX, k);

    cout << dinic() << "\n";

    return 0;
}