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

constexpr int N = 3010;
constexpr int M = 100;

ll n, m, k, q;
int a[3][N], ind[3][N], ans[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    rep(i, 0, n) {
        ans[i] = i;
    }
    rep(j, 0, 3) {
        rep(i, 0, n) {
            int x;
            cin >> x;
            x--;
            a[j][i] = x;
            ind[j][x] = i;
        }
    }

    auto cmp = [](int x, int y) {
        int xbig = 0;
        int ybig = 0;

        rep(i, 0, 3) {
            if (ind[i][x] > ind[i][y])
                ybig++;
            else xbig++;
        }

        if (xbig > ybig) {
            return true;
        } else return false;
    };

    sort(ans, ans + n, cmp);

    rep(i, 0, n) {
        cout << ans[i] + 1 << ' ';
    }
    cout << '\n';

    return 0;
}