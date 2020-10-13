// 11014: 컨닝 2
// https://www.acmicpc.net/problem/11014
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 80;
constexpr int NN = N * N;

int n, m;
int xCnt;
bool table[N][N];
bool visited[N][N];
bool visited2[N][N];
pair<int, int> match[N][N];

bool dfs(int x, int y) {
    if (!table[y][x] || visited[y][x])
        return false;

    visited[y][x] = true;

    const static pair<int, int> coord[6] = {
        {-1, -1}, {+1, -1},
        {-1, +0}, {+1, +0},
        {-1, +1}, {+1, +1}
    };

    FOR(i, 0, 6) {
        int dx = x + coord[i].first;
        int dy = y + coord[i].second;
        bool bound = (dx >= 0 && dx < m && dy >= 0 && dy < n);
        if (bound && table[dy][dx] &&
                (!visited2[dy][dx] || dfs(match[dy][dx].first, match[dy][dx].second))) {
            match[dy][dx] = {x, y};
            visited2[dy][dx] = true;
            return true;
        }
    }
    return false;
}

int bipartite() {
    memset(visited2, 0, sizeof(bool) * NN);
    int ret = 0;
    FOR(y, 0, n) {
        for (int x = 0; x < m; x += 2) {
            memset(visited, 0, sizeof(bool) * NN);
            ret += dfs(x, y);
        }
    }
    return ret;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    while (tc--) {
        xCnt = 0;
        cin >> n >> m;

        FOR(y, 0, n) {
            FOR(x, 0, m) {
                char c; cin >> c;
                if (c == '.') {
                    table[y][x] = true;
                } else {
                    table[y][x] = false;
                    xCnt++;
                }
            }
        }

        // 최대독립집합 = 정점갯수 (n * m - xCnt) - 최대매칭
        cout << n * m - xCnt - bipartite() << endl;
    }
    return 0;
}