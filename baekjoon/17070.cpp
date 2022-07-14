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

constexpr int N = 16;
constexpr int M = 1e9 + 7;

ll n;
bool arr[N][N];
int dp[N][N][3];

int getDp(int x, int y, int pos) {
    if (y == 0) return 0;
    if (x < 0) return 0;

    int& ref = dp[x][y][pos];
    if (ref != -1) return ref;

    auto op = [](int x, int y) {
        if (x >= 0 && x < n && y >= 0 && y < n) {
            if (arr[x][y])
                return true;
            else
                return false;
        } else {
            return true;
        }
    };

    if (pos == 0) {  // horizontal
        if (op(x, y) || op(x, y - 1))
            ref = 0;
        else {
            ref = getDp(x, y - 1, 0) + getDp(x, y - 1, 2);
        }
    } else if (pos == 1) {  // vertical
        if (op(x, y) || op(x - 1, y))
            ref = 0;
        else {
            ref = getDp(x - 1, y, 1) + getDp(x - 1, y, 2);
        }
    } else {  // diagonal
        if (op(x,y) || op(x-1,y) || op(x,y-1) || op(x-1,y-1))
            ref = 0;
        else {
            ref = 0;
            rep(i, 0, 3)
                ref += getDp(x-1,y-1,i);
        }
    }
    return ref;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    rep(i, 0, n) rep(j, 0, n) cin >> arr[i][j];
    memset(dp, -1, sizeof(dp));
    dp[0][1][0] = 1;

    int ans = 0;
    rep(i, 0, 3)
        ans += getDp(n - 1, n - 1, i);
    cout << ans << '\n';
    return 0;
}