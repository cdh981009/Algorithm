#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 500;

int ans[N][N];
int n;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        int k;
        cin >> n >> k;

        bool p = true;

        int e = 2;
        int o = 1;
        FOR(i, 0, n) {
            FOR(j, 0, k) {
                if (i % 2) {
                    if (e > n * k) {
                        p = false;
                        break;
                    }
                    ans[i][j] = e;
                    e += 2;
                } else {
                    if (o > n * k) {
                        p = false;
                        break;
                    }
                    ans[i][j] = o;
                    o += 2;
                }
            }
            if (!p) break;
        }
        if (p) {
            cout << "YES\n";
            FOR(i, 0, n) {
                FOR(j, 0, k) {
                    cout << ans[i][j] << ' ';
                }
                cout << '\n';
            }
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}