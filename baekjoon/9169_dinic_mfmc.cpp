// https://www.acmicpc.net/problem/9169
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 310;

int n, m;
bool b[N];
bool adj[N][N];
int level[N];
int flow[N][N];
int cache[N];

int SNK, SRC;

bool bfs() {
    memset(level, 0, sizeof(int) * N);
    queue<int> q;
    q.push(SRC);
    level[SRC] = 1;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == SNK)
            return true;
        
        FOR(nxt, 0, N) {
            if (adj[curr][nxt] && level[nxt] == 0 && flow[curr][nxt] > 0) {
                level[nxt] = level[curr] + 1;
                q.push(nxt);
            }
        }
    }

    return false;
}

int dfs(int node, int cap) {
    if (node == SNK)
        return cap;

    FOR(i, cache[node], N) {
        cache[node] = i;
        if (adj[node][i] && level[i] == level[node] + 1 && flow[node][i] > 0) {
            int c = dfs(i, min(cap, flow[node][i]));
            if (c > 0) {
                flow[node][i] -= c;
                flow[i][node] += c;
                return c;
            }
        }
    }
    
    return 0;
}

int dinic() {
    int f = 0;
    while (bfs()) {
        memset(cache, 0, sizeof(int) * N);
        int d;
        while ((d = dfs(SRC, INF)))
            f += d;
    }
    return f;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        
        memset(adj, 0, sizeof(bool) * N * N);
        memset(flow, 0, sizeof(int) * N * N);

        SRC = n;
        SNK = n + 1;

        FOR(i, 0, n) {
            cin >> b[i];
        }

        auto addEdge = [](int x, int y) {
            adj[x][y] = true;
            flow[x][y] = 1;
        };

        FOR(i, 0, n) {
            if (b[i])
                addEdge(SRC, i);
            else
                addEdge(i, SNK);
        }

        FOR(i, 0, m) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            addEdge(x, y);
            addEdge(y, x);
        }

        cout << dinic() << '\n';
    }

    return 0;
}