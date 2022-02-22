#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 101010;
constexpr int M = 1e9 + 7;

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
        ll n;
        cin >> n;
        string str;
        cin >> str;
        ll ans = 0;

        if (str[0] != 'D') {
            for (auto &c : str) {
                if (c == 'D')
                    c = 'R';
                else
                    c = 'D';
            }
        }
        // 항상 처음은 D

        bool onlyD = true;
        for (auto &c : str) {
            if (c != 'D') {
                onlyD = false;
                break;
            }
        }

        if (onlyD) {
            ans = n;
        } else {
            int sx, sy, ex, ey, cx, cy;
            cx = cy = 0;
            int si = -1;
            FOR(i, 0, str.size()) {
                bool d = str[i] == 'D';
                if (!d) {
                    if (si == -1) {
                        sx = cx;
                        sy = cy;
                        si = i;
                    }
                } else if (si == -1) {
                    ans += n - 1;
                }
                if (d)
                    cy++;
                else
                    cx++;
            }
            ex = cx;
            ey = cy;

            cx = sx, cy = sy;
            FOR(i, si, str.size()) {
                bool d = str[i] == 'D';
                if (!d) {
                    ans += cy - sy;
                    //cout << cy - sy << '\n';
                } else {
                    ans += cx - sx;
                    //cout << cx - sx << '\n';
                }
                if (d)
                    cy++;
                else
                    cx++;
            }

            ans = n * n - ans;
        }
        cout << ans << '\n';
    }

    return 0;
}