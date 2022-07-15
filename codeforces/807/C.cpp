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
constexpr int M = 100;

ll n, c, q, ans;
string str;

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
        cin >> n >> c >> q;
        cin >> str;
        vector<ll> v;
        vpll qs;
        v.push_back(n);

        rep(i, 0, c) {
            ll l, r;
            cin >> l >> r;
            v.push_back(r - l + 1 + v.back());
            qs.push_back({l, r});
        }

        rep(i, 0, q) {
            ll x;
            cin >> x;
            while (x > n) {
                auto hi = lower_bound(v.begin(), v.end(), x) - v.begin();
                hi--;
                auto rem = x - v[hi];
                x = rem + qs[hi].first - 1;
            }
            cout << str[x - 1] << '\n';
        }
    }

    return 0;
}