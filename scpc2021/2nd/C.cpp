#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 600;

int n, k;
ll ans;
int arr[N][N];
ll sv[N][N];
ll sd1[N][N];
ll sd2[N][N];

bool bound(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

void init() {
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            sv[i][j] = (bound(i - 1, j) ? sv[i - 1][j] : 0) + arr[i][j];
        }
    }
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            sd1[i][j] = (bound(i - 1, j - 1) ? sd1[i - 1][j - 1] : 0) + arr[i][j];
        }
    }
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            sd2[i][j] = (bound(i - 1, j + 1) ? sd2[i - 1][j + 1] : 0) + arr[i][j];
        }
    }
}

ll getH(int x, int y, int l) {
    if (x >= n) {
        int d = x - n + 1;
        x -= d;
        l -= d;
    }

    if (y < 0 || y >= n || x < 0 || l <= 0)
        return 0;

    return sv[x][y] - (bound(x - l, y) ? sv[x - l][y] : 0);
}

ll getD1(int x, int y, int l) {
    if (x >= n) {
        int d = x - n + 1;
        x -= d;
        y -= d;
        l -= d;
    }

    if (y >= n) {
        int d = y - n + 1;
        x -= d;
        y -= d;
        l -= d;
    }

    if (l <= 0 || x < 0 || y < 0)
        return 0;

    return sd1[x][y] - (bound(x - l, y - l) ? sd1[x - l][y - l] : 0);
}

ll getD2(int x, int y, int l) {
    if (x >= n) {
        int d = x - n + 1;
        x -= d;
        y += d;
        l -= d;
    }

    if (y < 0) {
        int d = -y;
        x -= d;
        y += d;
        l -= d;
    }

    if (l <= 0 || x < 0 || y >= n)
        return 0;

    return sd2[x][y] - (bound(x - l, y + l) ? sd2[x - l][y + l] : 0);
}

int main(int argc, char** argv) {
    int T, tc;

    freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    for (tc = 0; tc < T; tc++) {
        cin >> n >> k;
        FOR(i, 0, n) {
            FOR(j, 0, n) {
                cin >> arr[i][j];
            }
        }

        init();
        ans = 0;

        ll prv, crr, p1, p2, c1, c2;
        FOR(i, -k, n + k) {
            prv = p1 = p2 = 0;
            FOR(j, -k, n + k) {
                ll tmp = getH(i + k - 1, j - 1, 2 * k - 1);

                c1 = p1 - tmp + getD1(i, j + k - 1, k) + getD2(i + k - 1, j, k - 1);
                c2 = p2 + tmp - getD1(i + k - 1, j - 2, k - 1) - getD2(i, j - k - 1, k);
                crr = prv + c1 - c2;

                ans = max(ans, crr);

                prv = crr;
                p1 = c1;
                p2 = c2;
            }
        }

        cout << "Case #" << tc + 1 << endl;
        cout << ans << endl;
    }

    return 0;
}