// 2365: 숫자판 만들기
// https://www.acmicpc.net/problem/2365
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 110;
constexpr int MAXSTEP = 10000;

// Dinic: O(EV^2)

int n;
int SRC;
int SINK;

int flow[N][N];
int level[N];
int cache[N];

int arr[N];

int fullFlow;

// dinic's algorithm
// generate level graph
bool bfs() {
    memset(level, -1, sizeof(int) * (N));

    queue<int> q;
    q.push(SRC);
    level[SRC] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == SINK)
            break;

        int start, end;

        if (curr <= SINK) { // left side
            start = SINK + 1;
            end = SRC;
        } else {
            start = 0;
            end = SINK;
        }

        FOR_(next, start, end) {
            if (level[next] == -1 && flow[curr][next] > 0) {
                level[next] = level[curr] + 1;
                q.push(next);
            }
        }
    }

    return level[SINK] != -1;
}

// augment graph with blocking flow
int dfs(int curr, int cap) {
    if (curr == SINK) {
        return cap;
    }

    int start, end;

    if (curr <= SINK) { // left side
        start = SINK + 1;
        end = SRC;
    } else {
        start = 0;
        end = SINK;
    }

    for (int i = cache[curr]; i < end - start + 1; ++i) {
        cache[curr] = i;
        int next = start + i;

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
        memset(cache, 0, sizeof(int) * (N));
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
        flow[a][b] = c;
    };

    cin >> n;

    // (0 ... n - 1) : left, (n): sink
    // (n + 1 ... 2 * n) : right, (2 * n + 1) : src

    SRC = 2 * n + 1;
    SINK = n;

    FOR_(i, 0, n - 1) {
        cin >> arr[i];
    }

    FOR_(i, n + 1, 2 * n) {
        cin >> arr[i];
        fullFlow += arr[i];
    }

    auto isFullFlow = [](int k) {
        // reinitialize graph
        FOR_(i, 0, n - 1) {
            flow[SRC][i] = arr[i];
            flow[i][SRC] = 0;
        }

        FOR_(i, n + 1, 2 * n) {
            flow[i][SINK] = arr[i];
            flow[SINK][i] = 0;
        }

        FOR_(i, 0, n - 1) {
            FOR_(j, n + 1, 2 * n) {
                flow[i][j] = k;
                flow[j][i] = 0;
            }
        }

        return dinic() == fullFlow;
    };

    int x = MAXSTEP;
    for (int step = MAXSTEP; step > 0; step /= 2) {
        while (x - step >= 0 && isFullFlow(x - step))
            x -= step;
    }

    isFullFlow(x);
    cout << x << '\n';

    FOR_(i, 0, n - 1) {
        FOR_(j, n + 1, 2 * n) {
            cout << x - (flow[i][j]) << " ";
        }
        cout << '\n';
    }

    return 0;
}