// 11407: 책 구매하기 3
// https://www.acmicpc.net/problem/11407
#include <bits/stdc++.h>

using namespace std;

#define INF 1987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

// const int N = 20;
// const int X = 1 << 10;

const int N = 220;

int n, m;

const int SRC = 218;
const int SNK = 219;

int cap[N][N];
int cost[N][N];
vector<int> edge[N];
int cache[N];
int level[N];

int dist[N];
int from[N];
bool inQ[N];

queue<int> q;

bool spfa() {
    FOR(i, 0, N) {
        dist[i] = INF;
    }
    memset(inQ, false, sizeof(bool) * N);
    dist[SRC] = 0;
    inQ[SRC] = true;

    q.push(SRC);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        inQ[node] = false;

        for (auto nxt : edge[node]) {
            if (cap[node][nxt] <= 0)
                continue;
            int newDist = dist[node] + cost[node][nxt];
            if (newDist < dist[nxt]) {
                dist[nxt] = newDist;
                from[nxt] = node;
                if (!inQ[nxt])
                    q.push(nxt);
                inQ[nxt] = true;
            }
        }
    }

    return (dist[SNK] != INF);
}

// return {max flow, min cost}
pair<int, int> mcmf() {
    int f = 0, c = 0;

    while (spfa()) {
        int minFlow = INF;
        int curr = SNK;
        while (curr != SRC) {
            int prev = from[curr];
            minFlow = min(minFlow, cap[prev][curr]);
            curr = prev;
        }

        curr = SNK;
        f += minFlow;
        while (curr != SRC) {
            int prev = from[curr];
            cap[prev][curr] -= minFlow;
            cap[curr][prev] += minFlow;
            c += minFlow * cost[prev][curr];
            curr = prev;
        }
    }

    return {f, c};
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    auto addEdge = [](int s, int e, int f) {
        cap[s][e] = f;
        edge[s].push_back(e);
        edge[e].push_back(s);
    };

    cin >> n >> m;

    FOR(i, 0, n) {
        int x;
        cin >> x;
        addEdge(SRC, i, x);
    }

    FOR(i, 0, m) {
        int x;
        cin >> x;
        addEdge(i + n, SNK, x);
    }

    FOR(i, 0, m) {
        FOR(j, 0, n) {
            int x;
            cin >> x;
            addEdge(j, i + n, x);
        }
    }

    FOR(i, 0, m) {
        FOR(j, 0, n) {
            int x;
            cin >> x;
            cost[j][i + n] = x;
            cost[i + n][j] = -x;
        }
    }

    // min cost max flow
    auto res = mcmf();
    cout << res.first << '\n' << res.second << '\n';

    return 0;
}