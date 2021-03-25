// 1420: 학교 가지마!
// https://www.acmicpc.net/problem/1420
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e2;
constexpr int NN2 = N * N * 2;
int n, m, nm;

struct Edge {
    int dst;
    int flow;
    Edge* reverse;
};

vector<Edge*> edge[NN2];

int level[NN2];
int cache[NN2];

int SRC;
int SINK;

char grid[N][N];

inline int getCoord(int x, int y, bool incoming) {
    return (y * n + x) + nm * (incoming ? 0 : 1);
}

inline void addEdge(int src, int dst, int capacity) {
    Edge* e = new Edge;
    Edge* rev = new Edge;

    e->dst = dst;
    rev->dst = src;
    e->flow = capacity;
    rev->flow = 0;
    e->reverse = rev;
    rev->reverse = e;

    edge[src].push_back(e);
    edge[dst].push_back(rev);
}

inline void addUndirectedEdge(int src, int dst, int capacity) {
    Edge* e = new Edge;
    Edge* rev = new Edge;

    e->dst = dst;
    rev->dst = src;
    e->flow = capacity;
    rev->flow = capacity;
    e->reverse = rev;
    rev->reverse = e;

    edge[src].push_back(e);
    edge[dst].push_back(rev);
}

// dinic's algorithm
// generate level graph
bool bfs() {
    memset(level, -1, sizeof(int) * NN2);

    queue<int> q;
    q.push(SRC);
    level[SRC] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == SINK)
            break;

        for (auto e : edge[curr]) {
            if (level[e->dst] == -1 && e->flow > 0) {
                level[e->dst] = level[curr] + 1;
                q.push(e->dst);
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
        auto e = edge[curr][i];
        int next = e->dst;

        if (level[next] == level[curr] + 1 && e->flow > 0) {
            int c = dfs(next, min(cap, e->flow));
            if (c > 0) {
                e->flow -= c;
                e->reverse->flow += c;
                return c;
            }
        }
    }

    return 0;
}

int dinic() {
    int totalFlow = 0;
    while (bfs()) {
        memset(cache, 0, sizeof(int) * NN2);
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

    cin >> n >> m;
    nm = n * m;

    FOR(i, 0, n) {
        FOR(j, 0, m) {
            char c;
            cin >> c;
            grid[i][j] = c;
            switch (c) {
            case 'K':
                SRC = getCoord(i, j, false);
                break;
            case 'H':
                SINK = getCoord(i, j, true);
                break;
            }
        }
    }

    constexpr static pair<int, int> d[4] = {{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};

    FOR(i, 0, n) {
        FOR(j, 0, m) {
            char c = grid[i][j];
            if (c == '#')
                continue;

            // incoming to outgoing
            addEdge(getCoord(i, j, true), getCoord(i, j, false), 1);

            FOR(k, 0, 4) {
                auto& dxy = d[k];
                int px = i + dxy.first;
                int py = j + dxy.second;
                bool bound = (px >= 0 && px < n && py >= 0 && py < m);
                if (bound && grid[px][py] != '#') {
                    addEdge(getCoord(i, j, false), getCoord(px, py, true), 1);
                    addEdge(getCoord(px, py, false), getCoord(i, j, true), 1);
                }
            }
        }
    }

    bool impossible = false;
    for (auto e : edge[SRC]) {
        if (e->dst == SINK) {
            impossible = true;
            break;
        }
    }

    cout << (impossible ? -1 : dinic()) << endl;
    return 0;
}