#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<ll, ll>;

constexpr int N = 1e4;
constexpr int M = 1e9 + 7;

ll modpow(ll a, ll x) {
    ll ret = 1, base = a;
    while (x) {
        if (x % 2) {
            ret *= base; ret %= M;
        }
        base *= base; base %= M;
        x /= 2;
    }
    return ret;
}

ll inv(ll a) {
    return modpow(a, M - 2);
}

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }

    return a;
}

struct modint {
    ll x;
    modint(ll _x = 0): x(_x%M) {};

    modint operator+(const modint& o) {
        return modint(x + o.x);
    }
    modint operator-(const modint& o) {
        return modint(x - o.x + M);
    }
    modint operator*(const modint& o) {
        return modint(x * o.x);
    }
    modint operator/(const modint& o) {
        return modint(x * inv(o.x));
    }
};

int n, m, rb, cb, rd, cd, p;
modint q;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n >> m >> rb >> cb>> rd >> cd >> p;
        q = modint(p);
        q = modint(1) - q / 100;

        modint u, v;
        u = 0, v = 1;
        int r, c, dx, dy;
        dx = dy = -1;
        r = rb, c = cb;
        FOR(i, 0, 4 * (n - 1) * (m - 1)) {
            if (r + dx <= 0 || r + dx > n) dx = -dx;
            if (c + dy <= 0 || c + dy > m) dy = -dy;
            r += dx;
            c += dy;

            u = u + 1;
            if (r == rd || c == cd)
                u = u * q, v = v * q;
        }

        //cout << u.x << ' ' << v.x << '\n';

        cout << (u / (modint(1) - v)).x << '\n';
    }
    return 0;
}