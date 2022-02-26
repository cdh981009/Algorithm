#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 1000;
int a[N][N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    FOR(i, 0, n) {
        string str;
        cin >> str;
        FOR(j, 0, n) {
            if (str[j] == '#') {
                a[i][j] = 1;
            }
        }
    }

    auto oob = [&](int x, int y) {
        return (x >= 0 && x < n && y >= 0 && y < n);
    };

    bool pos = false;

    FOR(i, 0, n) {
        FOR(j, 0, n) {
            int cnt = 0;
            FOR(k, 0, 6) {
                int x = i + k;
                int y = j;
                if (!oob(x, y)) {
                    cnt = 0;
                    break;
                }
                cnt += a[x][y];
            }
            if (cnt >= 4) {
                pos = true;
                break;
            }

            cnt = 0;
            FOR(k, 0, 6) {
                int x = i;
                int y = j + k;
                if (!oob(x, y)) {
                    cnt = 0;
                    break;
                }
                cnt += a[x][y];
            }
            if (cnt >= 4) {
                pos = true;
                break;
            }

            cnt = 0;
            FOR(k, 0, 6) {
                int x = i + k;
                int y = j + k;
                if (!oob(x, y)) {
                    cnt = 0;
                    break;
                }
                cnt += a[x][y];
            }
            if (cnt >= 4) {
                pos = true;
                break;
            }

            cnt = 0;
            FOR(k, 0, 6) {
                int x = i - k;
                int y = j + k;
                if (!oob(x, y)) {
                    cnt = 0;
                    break;
                }
                cnt += a[x][y];
            }
            if (cnt >= 4) {
                pos = true;
                break;
            }
        }
        if (pos) break;
    }

    cout << (pos ? "Yes" : "No") << '\n';
    return 0;
}