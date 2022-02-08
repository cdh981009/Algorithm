#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 1e4;

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
        int n, m, rb, cb, rd, cd;
        cin >> n >> m >> rb >> cb>> rd >> cd;

        int tr, tc;
        if (rd >= rb) {
            tr = rd - rb;
        }
        if (rd < rb) {
            tr = (n - rb) + (n - rd);
        }
        if (cd >= cb) {
            tc = cd - cb;
        }
        if (cd < cb) {
            tc = (m - cb) + (m - cd);
        }
        cout << min(tr, tc) << '\n';
    }
    return 0;
}