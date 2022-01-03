#include <bits/stdc++.h>

using namespace std;

#define INF 6e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e3;

using ll = long long;

int n;
int arr[N][N];

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
        FOR(i, 0, 2 * n) {
            FOR(j, 0, 2 * n) {
                cin >> arr[i][j];
            }
        }

        ll ans = INF;

        vector<int> v;
        v.push_back(arr[0][n]);
        v.push_back(arr[0][2 * n - 1]);
        v.push_back(arr[n - 1][n]);
        v.push_back(arr[n - 1][2 * n - 1]);

        v.push_back(arr[n][0]);
        v.push_back(arr[n][n - 1]);
        v.push_back(arr[2 * n - 1][0]);
        v.push_back(arr[2 * n - 1][n - 1]);

        sort(v.begin(), v.end());

        ans = v[0];

        FOR(i, n, 2 * n) {
            FOR(j, n, 2 * n) {
                ans += arr[i][j];
            }
        }

        cout << ans << '\n';
    }

    return 0;
}