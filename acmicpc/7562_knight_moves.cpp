// 7562: Knight Moves
// https://www.acmicpc.net/problem/7562
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 300;

using pii = pair<int, int>;

int n;
pii s, e;
bool visited[N][N];

int bfs() {
    memset(visited, 0, sizeof(bool) * N * N);

    queue<pair<pii, int>> q;

    q.push({s, 0});
    visited[s.first][s.second] = true;

    const static pii move[8] = {
        {-2, -1},
        {-2, +1},
        {+2, -1},
        {+2, +1},
        {-1, +2},
        {-1, -2},
        {+1, +2},
        {+1, -2},
    };
    
    auto inBound = [](int x, int y) -> bool {
        return (x >= 0 && y >= 0 && x < n && y < n);
    };
    
    int ret = 0;

    while (!q.empty()) {
        auto pp = q.front();
        q.pop();

        auto here = pp.first;
        auto dist = pp.second;

        if (here == e) {
            ret = dist;
            break;
        }

        FOR(i, 0, 8) {
            int nx = here.first + move[i].first;
            int ny = here.second + move[i].second;

            if (inBound(nx, ny) && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({{nx, ny}, dist + 1});
            }
        }
    }

    return ret;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> s.first >> s.second >> e.first >> e.second;

        cout << bfs() << '\n';
    }

    return 0;
}