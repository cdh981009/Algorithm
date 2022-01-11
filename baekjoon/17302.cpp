#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;

constexpr int N = 2e3;
int n, m;
string str;
int ans[N][N];

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    FOR(i, 0, n) {
        cin >> str;
        FOR(j, 0, m) {
            bool x = (str[j] == 'B');

            int adj = 0;
            FOR(k, 0, 4) {
                int px = i + dx[k];
                int py = j + dy[k];
                if (px >= 0 && px < n && py >= 0 && py < m) adj++;
            }

            adj %= 2;

            ans[i][j] = (x + adj) % 2 + 2;
        }
    }

    cout << 1 << '\n';
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            cout << ans[i][j];
        }
        cout <<'\n';
    }

    return 0;
}