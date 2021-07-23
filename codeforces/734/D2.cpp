#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 201010;

int n, m, k;
char table[100][100];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n >> m >> k;
        bool ans = true;
        bool swapped = false;

        if (n % 2 == 1) {
            swapped = true;
            swap(n, m);
            k = (n * m) / 2 - k;
        }

        FOR(i, 0, n) {
            FOR(j, 0, m) {
                table[i][j] = ((i / 2) + j) % 2 ? 'c' : 'd';
            }
        }

        // n is always even number
        if (k % 2) {
            ans = false;
        } else {
            int x = 0;
            int y = k;
            while (y > 0) {
                if (m - x == 1) {
                    ans = false;
                    break;
                }

                FOR(i, 0, min(n, y)) {
                    FOR(j, 0, 2) {
                        table[i][x + j] = (((x + j) / 2) + i) % 2 ? 'a' : 'b';
                    }
                }
                y -= min(n, y);
                x += 2;
            }
        }

        cout << (ans ? "YES" : "NO") << '\n';
        if (ans) {
            if (swapped) {
                FOR(i, 0, m) {
                    FOR(j, 0, n) {
                        cout << table[j][i];
                    }
                    cout << '\n';
                }
            } else {
                FOR(i, 0, n) {
                    FOR(j, 0, m) {
                        cout << table[i][j];
                    }
                    cout << '\n';
                }
            }
        }
    }
    return 0;
}