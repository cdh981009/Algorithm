#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 302020;

using ll = long long;
using pii = pair<int, int>;

int n, m, k;
int x[N];
int y[N];
vector<int> xcnt[N];
vector<int> ycnt[N];
pii p[N];
ll ans;

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
        cin >> n >> m >> k;
        ans = 0;
        memset(xcnt, 0, sizeof(vector<int>) * (n + 10));
        memset(ycnt, 0, sizeof(vector<int>) * (m + 10));
        FOR(i, 0, n) {
            cin >> x[i];
        }
        FOR(i, 0, m) {
            cin >> y[i];
        }
        FOR(i, 0, k) {
            cin >> p[i].first >> p[i].second;
        }
        FOR(i, 0, k) {
            int px = p[i].first;
            int py = p[i].second;
            bool onX, onY;
            int xi, yi;
            xi = lower_bound(x, x + n, px) - x;
            yi = lower_bound(y, y + m, py) - y;
            onX = (x[xi] == px);
            onY = (y[yi] == py);

            if (onX && onY)
                continue;

            if (onX) {
                ycnt[yi].push_back(i);
            }
            if (onY) {
                xcnt[xi].push_back(i);
            }
        }

        FOR(i, 0, n + 10) {
            ll xs = xcnt[i].size();
            if (xs > 1) {
                ans += 1LL * xs * (xs - 1) / 2;
                sort(xcnt[i].begin(), xcnt[i].end(), [](int l, int r) -> bool {
                    return p[l].second < p[r].second;
                });
                int s = 0, e = 0;
                while (e < xs) {
                    while (e < xs && p[xcnt[i][e]].second == p[xcnt[i][s]].second) {
                        e++;
                    }
                    ans -= 1LL * (e - s) * (e - s - 1) / 2;
                    s = e;
                }
            }
        }
        FOR(i, 0, m + 10) {
            ll ys = ycnt[i].size();
            if (ys > 1) {
                ans += 1LL * ys * (ys - 1) / 2;
                sort(ycnt[i].begin(), ycnt[i].end(), [](int l, int r) -> bool {
                    return p[l].first < p[r].first;
                });
                int s = 0, e = 0;
                while (e < ys) {
                    while (e < ys && p[ycnt[i][e]].first == p[ycnt[i][s]].first) {
                        e++;
                    }
                    ans -= 1LL * (e - s) * (e - s - 1) / 2;
                    s = e;
                }
            }
        }

        cout << ans << '\n';
    }
    return 0;
}