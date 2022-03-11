#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pii>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 101010;
constexpr int M = 100;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<bool>> a(n, vector<bool>(m));
        FOR(i, 0, n) {
            string str;
            cin >> str;
            FOR(j, 0, m) {
                a[i][j] = (str[j] == '1');
            }
        }

        bool pos = true;

        auto cnt = [&](int x, int y) {
            int ret = 0;
            FOR(i, 0, 2) {
                FOR(j, 0, 2) {
                    ret += a[x + i][y + j];
                }
            }
            return ret;
        };

        FOR(i, 0, n - 1) {
            FOR(j, 0, m - 1) {
                if (cnt(i, j) == 3) {
                    pos = false;
                    break;
                }
            }
            if (!pos) break;
        }

        cout << (pos ? "YES" : "NO") << '\n';
    }

    return 0;
}