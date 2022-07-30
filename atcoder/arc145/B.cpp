#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 7)
#define fi first
#define se second
#define rep(i, a, b) for (ll i = (a); i < (b); ++i)
#define rep_(i, a, b) for (ll i = (a); i <= (b); ++i)
#define repr_(i, a, b) for (ll i = (a); i >= (b); --i)
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

ll n, a, b;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> a >> b;

    ll ans = 0;
    if (n < a) ans = 0;
    else {
        if (a <= b) ans = n - a + 1;
        else {
            ll lost = a - 1;
            lost += (a-b) * (n/a - 1);
            ll x = n % a;
            lost += max(0LL, x - b + 1);
            ans = n - lost;
        }
    }

    cout << ans << '\n';

    return 0;
}