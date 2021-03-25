// 17412: 도시 왕복하기 1
// https://www.acmicpc.net/problem/17412
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 400;
int n, p;
int flow[N][N];
vector<int> edge[N];
int level[N];
int cache[N];

const int SRC = 0;
const int SINK = 1;

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

    cin >> n >> p;

    auto addEdge = [](int a, int b, int c) {
        flow[a][b] = c;
        edge[a].push_back(b);
        edge[b].push_back(a);
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