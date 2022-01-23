#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 1e3 + 10;

bool cnt[N][N];
int ans;
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
        cin >> n;
        memset(cnt, false, sizeof(cnt));
        ans = 0;
        auto op = [](int x, int y) {
            return (x >= 0 && x < n && y >= 0 && y < n);
        };
        FOR(i, 0, n) {
            FOR(j, 0, n) {
                int x; cin >> x;
                const int dx[4] = {0, 0, -1, +1};
                const int dy[4] = {-1, +1, 0, 0};
                bool b = true;
                FOR(k, 0, 4) {
                    int px = i + dx[k];
                    int py = j + dy[k];
                    if (op(px, py) && cnt[px][py])
                        b = false;
                }
                if (b) {
                    ans ^= x;
                    FOR(k, 0, 4) {
                    int px = i + dx[k];
                    int py = j + dy[k];
                    if (op(px, py))
                        cnt[px][py] = true;
                    }
                }
            }
        }


        cout << ans << '\n';
    }
    return 0;
}