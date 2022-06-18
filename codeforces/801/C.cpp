#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
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
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pii>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 101010;
constexpr int M = 100;

bool pos;
ll n, m;
vector<vector<int>> arr;
vector<vector<pii>> dp;

pii solve(int i, int j) {
    if (i == n - 1 && j == m - 1) {
        return {arr[i][j], arr[i][j]};
    } else {
        if (dp[i][j].first != -1 || dp[i][j].second != -1) return dp[i][j];
        else {
            pii x = {INF, 0};
            pii ret;
            if (i + 1 < n) {
                ret = solve(i + 1, j);
                x.first = min(x.first, ret.first);
                x.second = max(x.second, ret.second);
            }

            if (j + 1 < m) {
                ret = solve(i, j + 1);
                x.first = min(x.first, ret.first);
                x.second = max(x.second, ret.second);
            }

            if (arr[i][j])
                x.first++, x.second++;
                

            return dp[i][j] = x;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        arr = vector<vector<int>>(n, vector<int>(m));
        FOR(i, 0, n) {
            FOR(j, 0, m) {
                cin >> arr[i][j];
                if (arr[i][j] == -1) arr[i][j] = 0;
            }
        }

        if ((n + m - 1) % 2) {
            pos = false;
        } else {
            dp = vector<vector<pii>>(n, vector<pii>(m, {-1, -1}));
            auto ret = solve(0, 0);
            ll x = (n + m - 1) / 2;
            //cout << ret.first << ' ' << ret.second << '\n';
            if (ret.first <= x && x <= ret.second) pos = true;
            else pos = false;
        }

        printYN(pos);
    }

    return 0;
}