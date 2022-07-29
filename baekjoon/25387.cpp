#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 7)
#define fi first
#define se second
#define rep(i, a, b) for (ll i = (a); i < (b); ++i)
#define rep_(i, a, b) for (ll i = (a); i <= (b); ++i)
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (ll i = (a); i <= (b); ++i)
#define printYN(pos) cout << (pos ? "YES" : "NO") << '\n'
#define printPOS(pos) cout << (pos ? "POSSIBLE" : "IMPOSSIBLE") << '\n'

using ll = long long;
using pii = pair<ll, ll>;
using pll = pair<ll, ll>;
using vi = vector<ll>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using mii = map<ll, ll>;
using mll = map<ll, ll>;

constexpr ll N = 301010;
constexpr ll M = 998244353;
constexpr ll B = 4e6;

ll n, q;
ll psum[N];

ll getPsum(ll l, ll r) {
    return (psum[r] - psum[l - 1] + M) % M;
}

struct Seg {
    ll n;
    vector<ll> vec;
    vector<ll> lazy;
    static const ll def = 0;

    Seg(ll _n, ll _def = def) {
        n = 1;
        while (n < _n) n *= 2;
        vec.resize(2 * n, _def);
        lazy.resize(2 * n, 0);
    }

    void prop(ll s, ll e, ll i) {
        if (lazy[i] == 0) return;

        vec[i] = lazy[i] * getPsum(s, e) % M;

        if (s != e) {
            lazy[2 * i]     = lazy[i];
            lazy[2 * i + 1] = lazy[i];
        }

        lazy[i] = 0;
    }

    // set update
    void update(ll node, ll nl, ll nr, ll l, ll r, ll val) {
        prop(nl, nr, node);

        if (nr < l || nl > r) return;

        if (l <= nl && nr <= r) {
            lazy[node] = val;
            prop(nl, nr, node);
            return;
        }

        ll m = (nl + nr) / 2;
        update(2 * node, nl, m, l, r, val);
        update(2 * node + 1, m + 1, nr, l, r, val);
        vec[node] = (vec[2 * node] + vec[2 * node + 1]) % M;
    }

    void update(ll l, ll r, ll val) {
        update(1, 0, n - 1, l, r, val);
    }

    // sum query
    ll query(ll node, ll nl, ll nr, ll l, ll r) {
        prop(nl, nr, node);

        if (nr < l || nl > r) return 0;

        if (l <= nl && nr <= r) {
            return vec[node];
        }

        ll m = (nl + nr) / 2;
        ll res1 = query(2 * node, nl, m, l, r);
        ll res2 = query(2 * node + 1, m + 1, nr, l, r);
        return (res1 + res2) % M;
    }

    ll query(ll l, ll r) {
        return query(1, 0, n - 1, l, r);
    }
};

struct Query {
    ll l, r, c;
};

vector<Query> qs;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    rep_(i, 1, n) {
        psum[i] = (psum[i-1] + (i * (n - i + 1) % M)) % M;
    }
    
    Seg seg(n + 1, 0);
    seg.update(1, n, q);

    rep_(i, 1, q) {
        ll l, r, c;
        cin >> l >> r >> c;
        qs.push_back({l, r, c});
    }

    ll ans = 0;
    for (int i = q - 1; i >= 0; --i) {
        auto& c = qs[i];
        ll res;
        ll j = seg.query(c.l, c.r);
        // cout << j << '\n';
        res =  (j - (i * getPsum(c.l, c.r)) % M + M) % M;
        res = res * (i + 1) % M;
        res = res * c.c % M;
        ans = (ans + res) % M;

        seg.update(c.l, c.r, i);
    }

    cout << ans << '\n';


    return 0;
}