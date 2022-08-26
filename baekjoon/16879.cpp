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

constexpr int N = 301;

int a[3][3] = {
    0, 1, 2,
    1, 2, 0,
    2, 0, 1};

int b[4][4] = {
    0, 1, 2, 3,
    1, 0, 3, 2,
    2, 3, 0, 1,
    3, 2, 1, 0};

int getNimber2(int x, int y) {
    if (x < 4 && y < 4) {
        return b[x][y];
    } else {
        return 4 * getNimber2(x / 4, y / 4) + b[x % 4][y % 4];
    }
}

int getNimber(int x, int y) {
    return 3 * getNimber2(x / 3, y / 3) + a[x % 3][y % 3];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int s = 0;

    // rep(i, 0, N) {
    //     rep(j, 0, N) {
    //         cout << getNimber(i, j) << ", ";
    //     }
    //     cout << '\n';
    // }

    rep(i, 0, n) {
        int x, y;
        cin >> x >> y;
        s ^= getNimber(x, y);
    }

    if (s)
        cout << "koosaga\n";
    else
        cout << "cubelover\n";

    return 0;
}