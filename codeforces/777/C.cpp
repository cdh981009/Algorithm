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

struct Ans {
    int x1, y1, x2, y2;
};

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
        vector<vector<bool>> a(n, vector<bool>(m, 0));
        FOR(i, 0, n) {
            string str;
            cin >> str;
            FOR(j, 0, m) {
                a[i][j] = (str[j] == '1');
            }
        }

        bool pos = !a[0][0];

        if (!pos) {
            cout << -1 << '\n';
        } else {
            vector<Ans> ans;

            for (int i = n - 1; i >= 0; --i) {
                for (int j = m - 1; j >= 0; --j) {
                    if (a[i][j] == 0) continue;
                    if (j == 0) {
                        ans.push_back({i - 1, j, i, j});
                    } else {
                        ans.push_back({i, j - 1, i, j});
                    }
                }
            }

            cout << ans.size() << '\n';
            for (auto &[x1, y1, x2, y2] : ans) {
                cout << x1 + 1 << ' ' << y1 + 1 << ' ' << x2 + 1 << ' ' << y2 + 1 << '\n';
            }
        }
    }

    return 0;
}