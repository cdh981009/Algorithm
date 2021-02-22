// 13261: 탈옥
// https://www.acmicpc.net/problem/13261
#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 5001;
constexpr int G = 801;

int n, b, s, r;
int adj[N][N];

long long val[N];
long long dp[N][N];

long long cost(int x, int y) {
    return (long long)(y - x) * (val[y] - (x - 1 > 0 ? val[x - 1] : 0));
}

// opt(i, j) <= opt(i + 1, j) 이므로 분할정복 트릭 사용가능

// dp[s][x] 부터 ans[e][x] 까지 값을 구하고 값의 후보를 p부터 q까지만 확인한다
void work(int s, int e, int x, int p, int q) {
    int mid = (s + e) / 2;

    long long& ref = dp[mid][x];
    ref = INT64_MAX;
    int opt = 0;

    FOR_(k, p, min(q, mid - 2)) {
        long long res = dp[k + 1][x - 1] + cost(mid, k);
        if (res < ref) {
            ref = res;
            opt = k;
        }
    }

    if (s <= mid - 1)
        work(s, mid - 1, x, p, opt);
    if (mid + 1 <= e)
        work(mid + 1, e, x, opt, q);
}

bool visited[N];
int dist[N];
int bdist[N];
int hq;

void dijkstra() {
    hq = b;

    FOR_(back, 0, 1) {
        memset(visited, 0, sizeof(bool) * N);
        priority_queue<pair<int, int>> pq;
        pq.push({0, hq});

        FOR(i, 0, n) {
            (back ? bdist[i] : dist[i]) = INF;
        }

        (back ? bdist[hq] : dist[hq]) = 0;

        while (!pq.empty()) {
            auto& p = pq.top();
            int d = -p.first;
            int curr = p.second;
            pq.pop();

            if (visited[curr])
                continue;
            visited[curr] = true;
            
            FOR(i, 0, n) {
                if ((back ? adj[i][curr] : adj[curr][i]) != -1 &&
                        !visited[i] &&
                        d + (back ? adj[i][curr] : adj[curr][i]) < (back ? bdist[i] : dist[i])) {
                    (back ? bdist[i] : dist[i]) = d + (back ? adj[i][curr] : adj[curr][i]);
                    pq.push({-(back ? bdist[i] : dist[i]), i});
                }
            }
        }
    }

    FOR(i, 0, b) {
        val[i] = dist[i] + bdist[i];
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(adj, -1, sizeof(int) * N * N);

    cin >> n >> b >> s >> r;

    FOR(i, 0, r) {
        int u, v, l;
        cin >> u >> v >> l;
        u--; v--;
        adj[u][v] = l;
    }

    dijkstra();

    sort(val, val + b);
    
    FOR(i, 1, b) {
        val[i] += val[i - 1];
    }

    // base case
    FOR(i, 0, b) {
        dp[i][1] = cost(i, b - 1);
    }
    // dp[s][x] 부터 ans[e][x] 까지 값을 구하고 값의 후보를 p부터 q까지만 확인한다

    FOR_(x, 2, s) {
        work(0, b - 1, x, 0, b - x);
    }

    cout << dp[0][s] << '\n';

    return 0;
    }