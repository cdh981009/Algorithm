#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 7)
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep_(i, a, b) for (int i = (a); i <= (b); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)
#define printYN(pos) cout << (pos ? "YES" : "NO") << '\n'
#define printPOS(pos) cout << (pos ? "POSSIBLE" : "IMPOSSIBLE") << '\n'

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 201010;
constexpr int M = 100;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        ll n;
        cin >> n;
        vector<vector<int>> arr(2, vector<int>(n));
        vector<vector<int>> dp(n, vector<int>(3, -1));
        rep(i, 0, 2) {
            rep(j, 0, n) {
                cin >> arr[i][j];
            }
        }

        auto getDp = [&](auto&& self, int i, int j) {
            if (i == n) return 0;

            auto& ref = dp[i][j];
            if (ref != -1) return ref;

            ref = self(self, i + 1, 0);

            if (j == 0) {
                ref = max(ref, self(self, i + 1, 1) + arr[0][i]);
                ref = max(ref, self(self, i + 1, 2) + arr[1][i]);
            } else if (j == 1) {
                ref = max(ref, self(self, i + 1, 2) + arr[1][i]);
            } else if (j == 2) {
                ref = max(ref, self(self, i + 1, 1) + arr[0][i]);
            }

            return ref;
        };

        cout << getDp(getDp, 0, 0) << '\n';
    }

    return 0;
}