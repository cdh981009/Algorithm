#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int(i) = (a); (i) < (b); ++(i))
#define FOR_(i, a, b) for (int(i) = (a); (i) <= (b); ++(i))

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

constexpr int N = 1010;
constexpr int M = 1010;

int n, m;
char arr[N][N];
bool b[N][N][4];

void f(int i, int j) {
    int x = 3 * i;
    int y = 3 * j;
    if (arr[x + 1][y + 1] == '.')
        return;
    b[i][j][0] = arr[x + 0][y + 1] == '#';
    b[i][j][1] = arr[x + 1][y + 2] == '#';
    b[i][j][2] = arr[x + 2][y + 1] == '#';
    b[i][j][3] = arr[x + 1][y + 0] == '#';
}

void g(int i, int j) {
    int x = 3 * i;
    int y = 3 * j;

    if (arr[x + 1][y + 1] == '#')
        return;
    arr[x + 1][y + 1] = '#';
    
    if (j > 0) {
        arr[x + 1][y + 0] = b[i][j - 1][1] ? '#' : '.';
    }
    if (i > 0) {
        arr[x + 0][y + 1] = b[i - 1][j][2] ? '#' : '.';
    }
    if (j < m - 1) {
        arr[x + 1][y + 2] = b[i][j + 1][3] ? '#' : '.';
    }
    if (i < n - 1) {
        arr[x + 2][y + 1] = b[i + 1][j][0] ? '#' : '.';
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    FOR(i, 0, 3 * n) {
        FOR(j, 0, 3 * m) {
            cin >> arr[i][j];
        }
    }

    FOR(i, 0, n) {
        FOR(j, 0, m) {
            f(i, j);
        }
    }

    FOR(i, 0, n) {
        FOR(j, 0, m) {
            g(i, j);
        }
    }

    FOR(i, 0, 3 * n) {
        FOR(j, 0, 3 * m) {
            cout << arr[i][j];
        }
        cout << '\n';
    }

    return 0;
}