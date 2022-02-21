#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;

constexpr int N = 310;
constexpr int M = 1e9 + 7;

int a[N][N];

ll sc[N][N];
ll mc[N][N];

ll ans = 0;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    FOR_(i, 1, n) {
        string str; cin >> str;
        FOR_(j, 1, m) {
            if (str[j-1] == 'E') {
                a[i][j] = 0;
            } else if (str[j-1] == 'S') {
                a[i][j] = 1;
            } else {
                a[i][j] = 2;
            }
        }
    }
    
    for (int i = n; i >= 1; --i) {
        for (int j = m; j >= 1; --j) {
            mc[i][j] = (a[i][j] == 2) + mc[i+1][j] + mc[i][j+1] - mc[i+1][j+1];       
            sc[i][j] = (a[i][j] == 1) * mc[i][j] + (sc[i+1][j] + sc[i][j+1] - sc[i+1][j+1] + M) % M;
            sc[i][j] %= M;
        }
    }

    FOR_(i, 1, n) {
        FOR_(j, 1, m) {
            if (a[i][j] == 0) {
                ans += sc[i][j];
                ans %= M;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}