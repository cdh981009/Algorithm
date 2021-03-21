#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1000;

bool cells[N][N];
int cellInfo[N][N][4];

int r, c;
long long ans;

const int LEFT = 0, RIGHT = 1, UP = 2, DOWN = 3;

int getInfo(int x, int y, int dir) {
    bool inBound = x >= 0 && x < r && y >= 0 && y < c;
    if (!inBound || cells[x][y] == 0) {
        return 0;
    }

    int& ref = cellInfo[x][y][dir];
    
    if (ref != -1) return ref;
    ref = 1;

    if (dir == LEFT)
        ref += getInfo(x - 1, y, dir);
    else if (dir == RIGHT)
        ref += getInfo(x + 1, y, dir);
    else if (dir == UP)
        ref += getInfo(x, y - 1, dir);
    else
        ref += getInfo(x, y + 1, dir);

    return ref;
}

long long cntL(int n, int m) {
    long long cnt = 0;
    int x;

    x = min(n / 2, m);
    cnt += max(0, x - 1);

    x = min(m / 2, n);
    cnt += max(0, x - 1);

    return cnt;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    FOR_(caseNum, 1, tc) {
        memset(cellInfo, -1, sizeof(int) * N * N * 4);

        cin >> r >> c;
        FOR(i, 0, r) {
            FOR(j, 0, c) {
                cin >> cells[i][j];
            }
        }

        ans = 0;

        FOR(i, 0, r) {
            FOR(j, 0, c) {
                int up = getInfo(i, j, UP);
                int down = getInfo(i, j, DOWN);
                int left = getInfo(i, j, LEFT);
                int right = getInfo(i, j, RIGHT);

                ans += cntL(up, left);
                ans += cntL(up, right);
                ans += cntL(down, left);
                ans += cntL(down, right);
            }
        }

        cout << "Case #" << caseNum << ": " << ans << '\n';
    }
    return 0;
}