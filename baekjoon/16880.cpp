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

int k[2][2] = {
    0, 1,
    3, 2
};

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
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int s = 0;

    // rep(i, 0, N) {
    //     rep(j, 0, N) {
    //         int x, y, z;
    //         x = i;
    //         y = j;
    //         if (x > y) swap(x, y);

    //         x %= 2;
    //         y %= 2;

    //         z = k[x][y];
    //         cout << z << ", ";
    //     }
    //     cout << '\n';
    // }

    rep(i, 0, n) {
        int x, y, z;
        char c;
        cin >> x >> y >> c;

        if (c == 'R') {
            z = getNimber2(x, y);
        } else if (c == 'B') {
            z = min(x, y);
        } else if (c == 'K') {
            if (x > y) swap(x, y);

            x %= 2;
            y %= 2;

            z = k[x][y];
        } else if (c == 'N') {
            if (x > y) swap(x, y);

            y -= 3 * (x / 3);
            x %= 3;


            if (x == 0) {
                z = 0;
            } else if (x == 1) {
                z = (y == x) ? 0 : 1;
            } else if (x == 2) {
                z = (y <= 3) ? 1 : 2;
            }
        } else {
            z = getNimber(x, y);
        }

        //cout << z << '\n';
        s ^= z;
    }

    if (s)
        cout << "koosaga\n";
    else
        cout << "cubelover\n";

    return 0;
}