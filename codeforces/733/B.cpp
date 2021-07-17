#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
constexpr int N = 20;
bool arr[2][N][N];
int cnt[2];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        int h, w; cin >> h >> w;
        cnt[0] = cnt[1] = 0;
        memset(arr, 0, sizeof(bool) * 2 * N * N);
        
        int dx[8] = {-1, +0, +1, -1, +1, -1, +0, +1};
        int dy[8] = {-1, -1, -1, +0, +0, +1, +1, +1};
        FOR(type, 0, 2) {
            auto& a = type == 0 ? arr[0] : arr[1];
            if (type == 0)
                a[0][0] = 1;
            else
                a[0][1] = 1;
            FOR(i, 0, h) {
                FOR(j, 0, w) {
                    if (i != 0 && i != h - 1 && j != 0 && j != w - 1)
                        continue;
                    bool place = true;
                    FOR(k, 0, 8) {
                        int px = i + dx[k];
                        int py = j + dy[k];
                        if (px >= 0 && px < h && py >= 0 && py < w && a[px][py] == 1) {
                            place = false;
                            break;
                        }
                    }
                    if (place) {
                        a[i][j] = 1;
                        cnt[type]++;
                    }
                }
            }
        }

        auto& ans = cnt[0] > cnt[1] ? arr[0] : arr[1];
        FOR(i, 0, h) {
            FOR(j, 0, w) {
                cout << ans[i][j];
            }
            cout << '\n';
        }
        cout << '\n';
    }
    return 0;
}