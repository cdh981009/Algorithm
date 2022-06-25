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
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pii>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 51010;
constexpr int M = 100;

ll n, m, k, q, ans;
ll a[N], b[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        rep(i, 0, n) cin >> a[i];
        cin >> k;
        rep(i, 0, k) cin >> b[i];

        bool pos = true;

        vector<pair<ll, ll>> ca, cb;

        rep(i, 0, n) {
            ll x = a[i];
            ll y = 1;
            while (x % m == 0) {
                y *= m;
                x /= m;
            }
            if (!ca.empty() && ca.back().first == x)
                ca.back().second += y;
            else
                ca.push_back({x, y});
        }

        rep(i, 0, k) {
            // cout << i << '\n';
            ll x = b[i];
            ll y = 1;
            while (x % m == 0) {
                y *= m;
                x /= m;
            }
            if (!cb.empty() && cb.back().first == x)
                cb.back().second += y;
            else
                cb.push_back({x, y});
        }

        if (cb.size() != ca.size()) pos = false;
        else {
            if (cb == ca) pos = true;
            else pos = false;
        }

        printYN(pos);
    }

    return 0;
}