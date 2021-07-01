#include <bits/stdc++.h>

using namespace std;

#define INF INT32_MAX
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using pii = pair<int, int>;
using ll = long long;

int w, e;
int ans;

double dp[61][61][61];
int bt[61][61][61];

void solve() {
    cin >> w >> e;
    dp[1][0][0] = dp[0][1][0] = dp[0][0][1] = 1. / 3 * (w + e);

    bt[1][0][0] = 0;
    bt[0][1][0] = 1;
    bt[0][0][1] = 2;

    double maxE = 0.;
    int rx, ry, rz;
    FOR_(sum, 2, 60) {
        FOR_(x, 0, sum) {
            FOR_(y, 0, sum - x) {
                int z = sum - x - y;

                double r, s, p;
                r = s = p = 0.0;

                if (x > 0)
                    r = dp[x - 1][y][z] + (double)(y) / (sum - 1) * e + (double)(z) / (sum - 1) * w;
                if (y > 0)
                    s = dp[x][y - 1][z] + (double)(z) / (sum - 1) * e + (double)(x) / (sum - 1) * w;
                if (z > 0)
                    p = dp[x][y][z - 1] + (double)(x) / (sum - 1) * e + (double)(y) / (sum - 1) * w;

                double v = max(max(r, s), p);
                dp[x][y][z] = v;
                if (v == r) {
                    bt[x][y][z] = 0;
                } else if (v == s) {
                    bt[x][y][z] = 1;
                } else {
                    bt[x][y][z] = 2;
                }

                if (sum == 60 && maxE < v) {
                    maxE = dp[x][y][z];
                    rx = x;
                    ry = y;
                    rz = z;
                }
            }
        }
    }

    string str;
    while (rx + ry + rz > 0) {
        int res = bt[rx][ry][rz];
        char o;
        if (res == 0) {
            rx--;
            o = 'R';
        } else if (res == 1) {
            ry--;
            o = 'S';
        } else {
            rz--;
            o = 'P';
        }
        str.push_back(o);
    }

    reverse(str.begin(), str.end());
    cout << str;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int x;
    int tc;
    cin >> tc >> x;

    FOR_(caseNum, 1, tc) {
        cout << "Case #" << caseNum << ": ";
        solve();
        cout << '\n';
    }
    return 0;
}