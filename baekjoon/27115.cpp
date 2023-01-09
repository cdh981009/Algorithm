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

int vec[3 * N][3 * N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    
    int n, m, k; cin >> n >> m >> k;

    rep(i, 0, k) {
        int y, x, p; cin >> y >> x >> p;
        y--, x--;

        vec[y + N - p][x + N] += 1;
        vec[y + N - p + 1][x + N] += 1;
        vec[y + N + p + 1][x + N] += 1;
        vec[y + N + p + 2][x + N] += 1;
        vec[y + N + 1][x + N + p] -= 1;
        vec[y + N + 1][x + N + p + 1] -= 1;
        vec[y + N + 1][x + N - p] -= 1;
        vec[y + N + 1][x + N - p - 1] -= 1;
    }

    rep(i, 0, 3*N) {
        rep(j, 0, 3*N) {
            if (i - 1 < 0 || j - 1 < 0) continue;
            vec[i][j] += vec[i - 1][j - 1];
        }
    }

    rep(i, 0, 3*N) {
        rep(j, 0, 3*N) {
            if (i - 1 < 0 || j + 1 >= 3*N) continue;
            vec[i][j] += vec[i - 1][j + 1];
        }
    }

    ll ans = 0;
    rep(i, N, N + n) {
        rep(j, N, N + m) {
            ans += (vec[i][j] > 0);
        }
    }

    cout << ans << '\n';

    return 0;
}