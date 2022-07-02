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

constexpr int N = 501010;
constexpr int M = 100;

int n, m, k, q, ans;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    using lll = __int128_t;
    vector<lll> a(n), b;
    rep(i, 0, n) {
        ll x; cin >> x;
        a[i] = x;
    }
    b = a;
    sort(b.begin(), b.end());
    bool pos = true;

    auto op = [](auto &x, auto &y) {
        lll mx = 1e18 + 100;
        lll z = 1;

        for (lll step = mx; step >= 1; step /= 2) {
            while (z + step < mx && x * y >= (z + step) * (z + step))
                z += step;
        }

        if (z * z == x * y) return true;
        return false;
    };

    rep(i, 0, n) {
        if (!op(a[i], b[i])) {
            pos = false;
            break;
        }
    }
    printYN(pos);

    return 0;
}