// 13161: 분단의 슬픔
// https://www.acmicpc.net/problem/13161
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 500 + 2;
int n;
int capacity[N][N];
vector<int> edge[N];
int level[N];
int cache[N]; 

int SRC;
int SINK;

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
            if (level[next] == -1 && capacity[curr][next] > 0) {
                level[next] = level[curr] + 1;
                q.push(next);
            }
        }
    }

    return level[SINK] != -1;
}

// augment graph with blocking capacity
int dfs(int curr, int cap) {
    if (curr == SINK) {
        return cap;
    }

    for (int i = cache[curr]; i < edge[curr].size(); ++i) {
        cache[curr] = i;
        int next = edge[curr][i];

        if (level[next] != level[curr] + 1 || capacity[curr][next] == 0)
            continue;
        int c = dfs(next, min(cap, capacity[curr][next]));
        if (c > 0) {
            capacity[curr][next] -= c;
            capacity[next][curr] += c;

            return c;
        }
    }

    return 0;
}

int dinic() {
    int totalFlow = 0;
    while (bfs()) {
        memset(cache, 0, sizeof(int) * N);
        int d;
        while (d = dfs(SRC, INF)) {
            totalFlow += d;
        }
    }
    return totalFlow;
}

int team[N];

vector<vector<int>> minCut() {
    queue<int> q;
    q.push(SRC);
    team[SRC] = 1;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (auto next : edge[curr]) {
            if (team[next] == 0 && capacity[curr][next] > 0) {
                team[next] = 1;
                q.push(next);
            }
        }
    }

    vector<vector<int>> res(2, vector<int>());

    FOR(i, 0, n) {
        res[team[i] == 0 ? 1 : 0].push_back(i);
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    SRC = n;
    SINK = n + 1;

    FOR(i, 0, n) {
        int t;
        cin >> t;
        if (t == 1) {
            capacity[SRC][i] = INF;
            edge[SRC].push_back(i);
            edge[i].push_back(SRC);
        } else if (t == 2) {
            capacity[i][SINK] = INF;
            edge[SINK].push_back(i);
            edge[i].push_back(SINK);
        }
    }

    FOR(i, 0, n) {
        FOR(j, 0, n) {
            int sadness;
            cin >> sadness;
            if (i <= j)
                continue;
            if (sadness > 0) {
                capacity[i][j] = sadness;
                capacity[j][i] = sadness;
                edge[i].push_back(j);
                edge[j].push_back(i);
            }
        }
    }

    cout << dinic() << endl;

    for (const auto& team : minCut()) {
        for (auto i : team) {
            cout << i + 1 << " ";
        }
        cout << "\n";
    }

    return 0;
}