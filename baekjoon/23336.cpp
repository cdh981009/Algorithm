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

constexpr int N = 1101010;
constexpr int M = 100;

struct Bit {
    vll vec;
    int n;

    Bit(int _n): n(_n + 1) {
        vec = vll(n, 0);
    }

    void update(int x, ll v) {
        int i = x + 1;
        while (i < n) {
            vec[i] += v;
            i += (i & -i);
        }
    }

    ll query(int x) {
        int i = x + 1;
        ll res = 0;
        while (i > 0) {
            res += vec[i];
            i -= (i & -i);
        }
        return res;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    Bit bit(n);
    ll inv = 0;
    rep(i, 0, n) {
        int x; cin >> x;
        x = n - x;
        inv += bit.query(x);
        bit.update(x, 1);
    }

    cout << inv << '\n';

    return 0;
}