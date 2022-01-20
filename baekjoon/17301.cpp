#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;

constexpr int N = 1e5 + 10;
constexpr int M = 1e9 + 7;

ll fac[N];
ll facInv[N];

ll modpow(ll a, ll x) {
    ll ret = 1;
    ll base = a;

    while (x) {
        if (x % 2) {
            ret *= base;
            ret %= M;
        }
        base *= base;
        base %= M;

        x /= 2;
    }

    return ret;
}

ll inv(ll a) {
    return modpow(a, M - 2);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fac[0] = 1;
    FOR(i, 1, N) {
        fac[i] = fac[i - 1] * i;
        fac[i] %= M;
    }

    facInv[N - 1] = inv(fac[N - 1]);
    for (int i = N - 2; i >= 0; --i) {
        facInv[i] = facInv[i + 1] * (i + 1);
        facInv[i] %= M;
    }

    ll ans = 0;
    int n;
    cin >> n;
    int nw, cw, cnw;
    nw = cw = cnw = 0;

    FOR(i, 0, n) {
        string str;
        cin >> str;
        bool n, c, nc;
        n = c = nc = false;
        for (auto &x : str) {
            if (x == 'N') {
                n = true;
            }
            if (x == 'C') {
                c = true;
                if (n)
                    nc = true;
            }
        }

        if (!nc) {
            if (n && c)
                cnw++;
            else if (n)
                nw++;
            else if (c)
                cw++;
        }
    }

    //cout << cnw << ' ' << nw << ' ' << cw << '\n';
    ll nx, cx;
    nx = cx = 0;
    FOR_(i, 0, nw) {
        nx += fac[nw] * facInv[nw - i];
        nx %= M;
    }

    FOR_(i, 0, cw) {
        cx += fac[cw] * facInv[cw - i];
        cx %= M;
    }

    //cout << nx << ' ' << cx << '\n';
    
    ll nn = 0;
    FOR_(i, 1, n) {
        nn += fac[n] * facInv[n - i];
        nn %= M;
    }

    ans = nx * cx;
    ans %= M;
    ans *= cnw + 1;
    ans = (ans + M - 1) % M;

    ans = (nn - ans + M) % M;

    cout << ans << '\n';
    return 0;
}