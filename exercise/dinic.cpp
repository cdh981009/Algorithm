// 17412: 도시 왕복하기 1
// https://www.acmicpc.net/problem/17412
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 400;
int n, p;
int cap[N][N];
vector<int> adj[N];
int flow[N][N];
int level[N];

const int SRC = 0;
const int SINK = 1;

// dinic's algorithm
inline int r(int a, int b) {
    return cap[a][b] - flow[a][b];
}

// generate level graph
bool bfs() {
    memset(level, -1, sizeof(int) * N);

    queue<int> q;
    q.push(SRC);
    level[SRC] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == SINK)
            break;

        for (auto next : adj[curr]) {
            if (level[next] == -1 && r(curr, next) > 0) {
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

    int f = 0;
    for (auto next : adj[curr]) {
        if (level[next] == level[curr] + 1 && r(curr, next) > 0) {
            int c = dfs(next, min(cap, r(curr, next)));
            if (c > 0) {
                f += c;
                cap -= c;
                flow[curr][next] += c;
                flow[next][curr] -= c;
            }
        }
    }

    if (f == 0)
        level[curr] = -1;
    return f;
}

int dinic() {
    int totalFlow = 0;
    while (bfs()) {
        totalFlow += dfs(SRC, INF);
    }
    return totalFlow;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> p;

    auto addEdge = [](int a, int b, int c) {
        cap[a][b] = c;
        adj[a].push_back(b);
        adj[b].push_back(a);
    };

    FOR(i, 0, p) {
        int s, d;
        cin >> s >> d;
        s--;
        d--;
        addEdge(s, d, 1);
    }

    cout << dinic() << endl;
    return 0;
}