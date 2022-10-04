#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 7)
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep_(i, a, b) for (int i = (a); i <= (b); ++i)
#define repr_(i, a, b) for (int i = (a); i >= (b); --i)
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

ll n, m, k, q, ans;
ll a[2][N];
ll dp[2][N][2];

// return num of dust need to be manually cleaned
ll getDp(int row, int x, int erased) {
    if (x == n) return 0;
    
    ll &ref = dp[row][x][erased];
    if (ref != -1) return ref;
    ref = INF;

    if (a[1 - row][x] == 0 || erased) { // below is empty
        ref = getDp(row, x + 1, 0);
    } else {
        // ignore below
        ref = 1 + getDp(row, x + 1, 0);

        if (a[row][x+1] == 0) {
            ref = min(ref, getDp(1 - row, x + 1, 0));
        } else {
            ref = min(ref, min(1 + getDp(1 - row, x + 1, 1), // clean next, goto below
                      1 + getDp(row, x + 1, 0))); // clean below, goto next
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

    memset(dp, -1, sizeof(dp));

    cin >> n;
    ans = 0;

    rep(i, 0, 2) {
        rep(j, 0, n) {
            char x ; cin >> x;
            x -= '0';
            a[i][j] = x;
            ans += a[i][j];
        }
    }

    ans -= getDp(0, 0, 0);

    cout << ans << '\n';

    return 0;
}