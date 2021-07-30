#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 500;
int board[N][N];
int mp[N][N];

bool visited[N][N];
int dist[N][N];

int weight[10];

struct Unit {
    int m, t;
    int a, b;
};

vector<Unit> units;

int n, m, h, w, k;

int dx[4] = {0, 0, +1, -1};
int dy[4] = {+1, -1, 0, 0};

void query(int x, int a, int b) {
    auto& u = units[x];

    if (board[a][b] != -1 || mp[a][b] == INF)
        return;

    auto bound = [](int x, int y) {
        return x >= 0 && x < h && y >= 0 && y < w;
    };

    FOR_(i, -20, 20) {
        FOR_(j, -20, 20) {
            int x = u.a + i;
            int y = u.b + j;
            if (bound(x, y)) {
                visited[x][y] = false;
                dist[x][y] = -1;
            }
        }
    }

    bool pos = false;

    priority_queue<pair<int, pair<int, int>>> q;
    q.push({u.m,
            {u.a, u.b}});
    dist[u.a][u.b] = u.m;

    auto moveable = [&](int t, int m, int x, int y) {
        if (visited[x][y])
            return false;

        if (mp[x][y] > m)
            return false;

        bool block = false;

        if (board[x][y] != -1 && units[board[x][y]].t != t)
            return false;
        
        FOR(i, 0, 4) {
            int px = x + dx[i];
            int py = y + dy[i];

            if (bound(px, py) && board[px][py] != -1 && units[board[px][py]].t != t && !(x == a && y == b)) {
                block = true;
                break;
            }
        }

        if (block)
            return false;

        return true;
    };

    while (!q.empty()) {
        auto& p = q.top();
        int x = p.second.first;
        int y = p.second.second;
        int m = p.first;
        q.pop();

        if (x == a && y == b) {
            pos = true;
            break;
        }

        if (visited[x][y])
            continue;

        visited[x][y] = true;

        FOR(i, 0, 4) {
            int px = x + dx[i];
            int py = y + dy[i];

            if (bound(px, py) && dist[px][py] < m - mp[px][py] && moveable(u.t, m, px, py)) {
                dist[px][py] = m - mp[px][py];
                q.push({m - mp[px][py],
                        {px, py}});
            }
        }
    }

    if (pos) {
        board[u.a][u.b] = -1;
        board[a][b] = x;
        u.a = a;
        u.b = b;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> h >> w;
    memset(board, -1, sizeof(int) * N * N);

    FOR(i, 0, h) {
        FOR(j, 0, w) {
            cin >> mp[i][j];
        }
    }

    FOR_(i, 1, n) {
        cin >> weight[i];
        if (weight[i] == -1)
            weight[i] = INF;
    }

    FOR(i, 0, h) {
        FOR(j, 0, w) {
            mp[i][j] = weight[mp[i][j]];
        }
    }

    cin >> m;

    FOR(i, 0, m) {
        int f, t, a, b;
        cin >> f >> t >> a >> b;
        units.push_back({f, t, a, b});
        board[a][b] = i;
    }

    cin >> k;

    FOR(i, 0, k) {
        int u, a, b;
        cin >> u >> a >> b;
        u--;
        query(u, a, b);
    }

    FOR(i, 0, m) {
        auto& u = units[i];
        cout << u.a << ' ' << u.b << '\n';
    }

    return 0;
}