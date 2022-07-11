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

constexpr int N = 7000;
constexpr int M = 100;

int n;
vector<vector<char>> arr;

void solve(int sz, int x, int y) {
    if (sz == 3) {
        arr[x][y+2] = '*';
        arr[x+1][y+1] = arr[x+1][y+3] = '*';
        rep(i,0,5)
            arr[x+2][y+i] = '*';
    } else {
        solve(sz / 2, x, y + sz / 2);
        solve(sz / 2, x + sz / 2, y);
        solve(sz / 2, x + sz / 2, y + sz);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    arr = vector<vector<char>> (n, vector<char>(2 * n + 1, ' '));
    solve(n, 0, 0);

    rep(i, 0, n) {
        rep(j, 0, 2 * n + 1) {
            cout << arr[i][j];
        }
        cout << '\n';
    }

    return 0;
}