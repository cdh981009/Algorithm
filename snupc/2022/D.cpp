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

constexpr int N = 2000;
constexpr int M = 1000000000 + 7;

struct Mint {
    ll mod = 0;
    ll quo = 0;

    bool operator<(const Mint& o) {
        if (mod != o.mod)
            return mod < o.mod;
        else
            return quo < o.quo;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;
    Mint x = {0, k};

    auto op = [&](char o, ll a) {
        if (o == '-') {
            x.quo -= a;
            if (x.quo < 0) {
                x.mod--;
                x.quo += M;
                if (x.mod < 0) {
                    x.mod = x.quo = 0;
                }
            }
        } else if (o == '+') {
            x.quo += a;
            if (x.quo >= M) {
                x.quo -= M;
                x.mod++;
            }
        } else {
            x.quo *= a;
            x.mod *= a;
            if (x.mod >= M) x.mod = M;
            x.mod += x.quo / M;
            if (x.mod >= M) x.mod = M;
            x.quo %= M;
        }

        if (x.mod >= M) x.mod = M;
    };

    rep(i, 0, n) {
        char c1, c2;
        ll a1, a2;
        cin >> c1 >> a1 >> c2 >> a2;

        if (c2 == '-') {
            swap(c1, c2);
            swap(a1, a2);
        } else if (c1 != '-' && c2 == '+') {
            swap(c1, c2);
            swap(a1, a2);
        }

        if (c1 == c2) {
            if (c1 == '-') {
                if (a1 > a2) swap(a1, a2);
            } else {
                if (a1 < a2) swap(a1, a2);
            }
            op(c1, a1);
        } else if (c1 == '-') {
            if (c2 == '*' && a2 == 0) {
                op(c1, a1);
            } else {
                op(c2, a2);
            }
        } else if (c1 == '+' && c2 == '*') {
            if (x.mod == 0 && x.quo == 0) {
                op(c1, a1);
            } else if (a2 <= 1) {
                op(c1, a1);
            } else if (x.mod >= 1) {
                op(c2, a2);
            } else {
                Mint y = x;
                op(c1, a1);

                swap(x, y);
                op(c2, a2);

                if (x < y) swap(x, y);
            }
        }
    }

    cout << x.quo << '\n';

    return 0;
}