#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 55;

int ans;
char arr[N][N];
int n, m, r, c;

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
        cin >> n >> m >> r >> c;
        r--, c--;
        string str;
        bool allw = true;
        FOR(i, 0, n) {
            cin >> str;
            FOR(j, 0, m) {
                arr[i][j] = (str[j] == 'W' ? 0 : 1);
                if (arr[i][j] == 1)
                    allw = false;
            }
        }

        if (allw) {
            cout << -1 << '\n';
            continue;
        }

        if (arr[r][c]) {
            cout << 0 << '\n';
            continue;
        }

        bool cb = false, rb = false;

        FOR(i, 0, n) {
            if (arr[i][c])
                cb = true;
        }
        FOR(i, 0, m) {
            if (arr[r][i])
                rb = true;
        }

        int ans;

        if (cb || rb) {
            ans = 1;
        } else
            ans = 2;

        cout << ans << '\n';
    }
    return 0;
}