#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 30;
constexpr int M = 900;

int n, m;
int arr1[N][N];
int arr2[N][N];
bool visited[N][N];

int cnt = 0;
int ind[N][N];
int val[M];

int dx[4] = {0, 0, -1, +1};
int dy[4] = {-1, +1, 0, 0};

bool inBound(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void fill(int x, int y) {
    visited[x][y] = true;
    ind[x][y] = cnt;

    FOR(i, 0, 4) {
        int px = x + dx[i];
        int py = y + dy[i];

        if (inBound(px, py) && !visited[px][py] && arr1[px][py] == arr1[x][y]) {
            fill(px, py);
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            cin >> arr1[i][j];
        }
    }

    FOR(i, 0, n) {
        FOR(j, 0, m) {
            cin >> arr2[i][j];
        }
    }

    FOR(i, 0, n) {
        FOR(j, 0, m) {
            if (!visited[i][j]) {
                fill(i, j);
                cnt++;
            }
        }
    }

    memset(val, -1, sizeof(int) * M);
    bool pos = true;
    bool one = true;
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            int& x = val[ind[i][j]];
            if (x == -1) {
                x = arr2[i][j];
                if (arr1[i][j] != arr2[i][j]) {
                    if (one) {
                        one = false;
                    } else {
                        pos = false;
                        break;
                    }
                }
            }
            else if (x != arr2[i][j]) {
                pos = false;
                break;
            }
        }
        if (!pos)
            break;
    }

    cout << (pos ? "YES" : "NO") << '\n';

    return 0;
}