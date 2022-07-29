#include <bits/stdc++.h>

using namespace std;

#define INF (1e9+7)
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

constexpr int N = 301010;
constexpr int M = 1010100;

ll n, m, k, q, ans;
ll fac[M];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    rep(i, 1, M)
        fac[i] = i;

    for(ll i = 2; i * i < M; ++i) {
        if (fac[i] == i) {
            for (ll j = (ll)i * i; j < M; j += i) {
                if (fac[j] == j)
                    fac[j] = i;
            }
        }
    }

    ll tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        map<ll, ll> mp;
        rep(i, 0, n) {
            map<ll, ll> mp2;
            ll x;
            cin >> x;
            while (x > 1) {
                ll f = fac[x];
                x /= f;
                mp2[f]++;
            }
            ll res = 1;
            for (auto &[k, v] : mp2)
                if (v % 2 == 1)
                    res *= k;
            mp[res]++;
        }

        ll mx = 0;
        ll sum = 0;
        for (auto &[k, v] : mp) {
            mx = max(mx, v);
            if (v % 2 == 0 || k == 1)
                sum += v;
        }

        cin >> q;
        rep(i, 0, q) {
            ll w; cin >> w;
            if (w == 0) {
                ans = mx;
            } else {
                ans = max(mx, sum);
            }

            cout << ans << '\n';
        }
    }

    return 0;
}