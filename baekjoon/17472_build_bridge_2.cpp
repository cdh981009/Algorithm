// 17472: 다리 만들기 2
// https://www.acmicpc.net/problem/17472
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 10;
constexpr int I = 6;

int n, m;
int iCnt = 0;

int mp[N][N];
bool visited[N][N];

int adj[I][I];
vector<pair<int, pair<int, int>>> edges;

int root[I];

vector<pair<int, int>> islandCells[I];

int find(int x) {
    return root[x] == x ? x : (root[x] = find(root[x]));
}

bool same(int x, int y) {
    return find(x) == find(y);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    root[y] = x;
}

int kruscal() {
    FOR(i, 0, iCnt) {
        FOR(j, i + 1, iCnt) {
            if (adj[i][j] != INF) {
                edges.push_back({adj[i][j], {i, j}});
            }
        }
    }

    FOR(i, 0, iCnt) {
        root[i] = i;
    }

    sort(edges.begin(), edges.end());

    int ans = 0;
    int connect = 1;
    FOR(i, 0, edges.size()) {
        auto p = edges[i];
        int x = p.second.first;
        int y = p.second.second;

        if (!same(x, y)) {
            connect++;
            ans += p.first;
            unite(x, y);
        }
    }

    return (connect != iCnt) ? -1 : ans;
}

bool inBound(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < m);
}

const static pair<int, int> mv[4] = {
    {0, -1}, {0, +1}, {-1, 0}, {+1, 0}
};

void dfs(int x, int y) {
    mp[x][y] = iCnt;
	visited[x][y] = true;

    bool put = false;
    FOR(i, 0, 4) {
        int nx = x + mv[i].first;
        int ny = y + mv[i].second;
        if (!inBound(nx, ny))
            continue;

        if (!visited[nx][ny] && mp[nx][ny] != 0)
            dfs(nx, ny);

        if (mp[nx][ny] == 0 && !put) { // adjacent cell is empty
            islandCells[iCnt - 1].push_back({x, y});
            put = true;
        }
    }
}

void floodFill() {
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            if (!visited[i][j] && mp[i][j] != 0) {
                iCnt++;
                dfs(i, j);
            }
        }
    }
}

// TODO
void getAdj() {
    FOR(i, 0, iCnt) {
        FOR(j, 0, iCnt) {
            adj[i][j] = INF;
        }
    }

    FOR(i, 0, iCnt) {
        for (auto& p : islandCells[i]) {
            FOR(j, 0, 4) {
                int dirX = mv[j].first;
                int dirY = mv[j].second;

                int dist = 0;
                int cx = p.first;
                int cy = p.second;
                cx += dirX;
                cy += dirY;
                while (inBound(cx, cy) && mp[cx][cy] == 0) {
                    dist++;
                    cx += dirX;
                    cy += dirY;
                }
                if (dist >= 2 && inBound(cx, cy) && mp[cx][cy] != 0 && mp[cx][cy] -1 != i) {
                    int k = mp[cx][cy] - 1;
                    adj[i][k] = min(adj[i][k], dist);
                    adj[k][i] = min(adj[k][i], dist);
                }
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            cin >> mp[i][j];
        }
    }

    floodFill();

    getAdj();

    cout << kruscal() << '\n';

    return 0;
}