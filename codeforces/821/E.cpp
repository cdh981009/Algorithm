#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 7)
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep_(i, a, b) for (int i = (a); i <= (b); ++i)
#define repr_(i, a, b) for (int i = (a); i >= (b); --i)
#define printYN(pos) cout << (pos ? "YES" : "NO") << '\n'
#define printPOS(pos) cout << (pos ? "POSSIBLE" : "IMPOSSIBLE") << '\n'

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 120;
constexpr int M = 100;

ll a[N][N];
ll b[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    rep(i, 0, n) {
        ll t, x, y;
        cin >> t >> x >> y;
        bool pos = false;

        if (t >= x + y) {
            memset(a, 0, sizeof(a));
            memset(b, 0, sizeof(b));

            // simulate t - (x + y)
            a[0][0] = t - (x + y);
            rep(i, 0, N) {
                rep(j, 0, N) {
                    if (i + j == x + y) {
                        b[i] = a[i][j];
                    }
                    if (i + 1 < N)
                        a[i + 1][j] += a[i][j] / 2;
                    if (j + 1 < N)
                        a[i][j + 1] += (a[i][j] + 1) / 2;
                }
            }

            memset(a, 0, sizeof(a));

            // simulate t - (x + y) + 1
            a[0][0] = t - (x + y) + 1;
            int c = 0;
            rep(i, 0, N) {
                rep(j, 0, N) {
                    if (i + j == x + y) {
                        if (b[i] != a[i][j]) {
                            if (x == i && y == j) pos = true;
                        }
                    }
                    if (i + 1 < N)
                        a[i + 1][j] += a[i][j] / 2;
                    if (j + 1 < N)
                        a[i][j + 1] += (a[i][j] + 1) / 2;
                }
            }
        }

        printYN(pos);
    }


    return 0;
}