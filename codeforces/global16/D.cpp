#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;


constexpr int N = 301;
int n, m, k;
int ans;
pii p[N];

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
        cin >> n >> m;
        ans = 0;
        k = n * m;
        FOR(i, 0, k) {
            cin >> p[i].first;
            p[i].second = i;
        }
        sort(p, p + k);
        FOR(i, 0, k) {
            p[i].second = -p[i].second;
        }

        FOR(i, 0, n) {
            sort(p + i * m, p + (i + 1) * m);
            FOR(j, 0, m) {
                FOR(k, j + 1, m) {
                    if (p[i * m + j].second > p[i * m + k].second)
                        ans++;
                }
            }
        }

        cout << ans << '\n';
    }
    return 0;
}