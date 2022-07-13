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

constexpr int N = 201010;
constexpr int M = 1e9 + 7;

ll modpow(ll a, ll x) {
    ll res = 1;
    ll base = a;

    while (x) {
        if (x % 2) res = res * base % M;
        base = base * base % M;
        x /= 2;
    }

    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n; cin >> n;
    ll sum = 0;
    rep(i, 0, n) {
        ll x, y;
        cin >> x >> y;
        sum = (sum + y * modpow(x, M - 2) % M) % M;
    }

    cout << sum << '\n';

    return 0;
}