#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pii>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 55;
constexpr int M = 998244353;

int n, m, k;
vi w;

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

ll fac[N];
ll dp[N][N][N];

ll getDp(int k, int m, int ind) {
    if (ind == n) {
        return (k == 0 && m == 0);
    }

    ll &ref = dp[k][m][ind];

    if (ref != -1) return ref;

    modint ret = 0;

    ret = getDp(k, m, ind + 1);
    
    if (m >= 1) {
        FOR_(i, 1, k) {
            ret = ret + modint(getDp(k - i, m - 1, ind + 1)) * modint(modpow(w[ind], i)) / modint(fac[i]);
        }
    }

    return ref = ret.x;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;
    w = vi(n);
    int sum = 0;

    memset(dp, -1, sizeof(dp));

    fac[0] = 1;
    FOR(i, 1, N) {
        fac[i] = fac[i - 1] * i % M; 
    }

    FOR(i, 0, n) {
        cin >> w[i];
        sum += w[i];
    }

    if (k < m)
        cout << 0 << '\n';
    else {
        modint ret = getDp(k, m, 0);
        ret = ret / modint(modpow(sum, k));
        ret = ret * fac[k];

        cout << ret.x << '\n';
    }

    
    return 0;
}