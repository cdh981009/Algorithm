#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = (1 << 10);

using ll = long long;
using pii = pair<int, int>;

int arr[N][N];
int k;

void solve(int k, int xo, int yo, int a, int b) {
    if (k == 1) {
        FOR(i, 0, 2) {
            FOR(j, 0, 2) {
                int x = xo + i;
                int y = yo + j;
                if (x == xo + a && y == yo + b)
                    continue;
                arr[x][y] = ((x / 2) + (y / 2)) % 2 ? 1 : 2;
            }
        }
    } else {
        int m = (1 << (k - 1));
        int q;
        if (a < m && b < m)
            q = 1;
        else if (a >= m && b < m)
            q = 2;
        if (a < m && b >= m)
            q = 3;
        if (a >= m && b >= m)
            q = 4;
        solve(k - 1, xo + 0, yo + 0, q == 1 ? a : m - 1,        q == 1 ? b : m - 1);
        solve(k - 1, xo + m, yo + 0, q == 2 ? a - m : 0,        q == 2 ? b : m - 1);
        solve(k - 1, xo + 0, yo + m, q == 3 ? a : m - 1,        q == 3 ? b - m : 0);
        solve(k - 1, xo + m, yo + m, q == 4 ? a - m : 0,        q == 4 ? b - m : 0);

        int px = q % 2  ? m - 1 : m;
        int py = q <= 2 ? m - 1 : m;

        FOR(i, 0, 2) {
            FOR(j, 0, 2) {
                int x = xo + m - 1 + i;
                int y = yo + m - 1 + j;
                if (x == px + xo && y == py + yo)
                    continue;
                arr[x][y] = 3;
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int tc; cin >> tc;
    cin >> k;

    while (tc--) {
        int a, b; cin >> a >> b;
        a--;
        b--;

        memset(arr, 0, sizeof(int) * N * N);

        solve(k, 0, 0, a, b);

        FOR(i, 0, 1 << k) {
            FOR(j, 0, 1 << k) {
                int x = arr[i][j];
                char o;
                if (x == 0) {
                    o = '@';
                } else if (x == 1) {
                    o = 'a';
                } else if (x == 2) {
                    o = 'b';
                } else {
                    o = 'c';
                }
                cout << o;
            }
            cout << '\n';
        }
    }

    return 0;
}