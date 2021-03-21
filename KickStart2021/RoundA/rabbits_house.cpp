#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 300;

int cells[N][N];
bool visited[N][N];

int r, c;
long long ans;

using pii = pair<int, int>;
using cell = pair<int, pii>;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    FOR_(caseNum, 1, tc) {
        memset(visited, 0, sizeof(bool) * N * N);

        cin >> r >> c;
        FOR(i, 0, r) {
            FOR(j, 0, c) {
                cin >> cells[i][j];
            }
        }

        ans = 0;

        priority_queue<cell> q;

        FOR(i, 0, r) {
            FOR(j, 0, c) {
                q.push({cells[i][j], {i, j}});
            }
        }

        while (!q.empty()) {
            auto &top = q.top();
            int h = top.first;
            int x = top.second.first;
            int y = top.second.second;
            q.pop();

            if (visited[x][y])
                continue;
            visited[x][y] = true;

            pii dir[4] = {{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};

            FOR(i, 0, 4) {
                int dx = x + dir[i].first;
                int dy = y + dir[i].second;

                bool inBound = dx >= 0 && dx < r && dy >= 0 && dy < c;
                if (!inBound || visited[dx][dy])
                    continue;
                
                if (cells[dx][dy] < h - 1) {
                    ans += h - 1 - cells[dx][dy];
                    cells[dx][dy] = h - 1;
                    q.push({cells[dx][dy], {dx, dy}});
                }
            }
        }

        cout << "Case #" << caseNum << ": " << ans << '\n';
    }
    return 0;
}