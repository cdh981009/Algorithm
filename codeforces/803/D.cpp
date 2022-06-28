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

ll n, m, k, q, ans;
ll arr[N];

int main() {
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll tc;
    cin >> tc;
    while (tc--) {
        cin >> n;

        auto op = [](int l, int r) -> bool {
            vector<ll> v;
            cout << "? " << l << " " << r << '\n';
            cout.flush();

            rep(i, 0, r - l + 1) {
                ll x; cin >> x;
                v.push_back(x);
            }
            
            ll cnt = 0;
            rep(i, 0, r - l + 1) {
                ll x = v[i];
                if (x >= l && x <= r) cnt++;
            }
            return (cnt % 2);
        };

        ll s, e;
        s = 1;
        e = n;
        rep(i, 0, 15) {
            ll m = (s + e) / 2;
            bool res = op(s, m);
            if (res == true) {
                e = m;
            } else {
                s = m + 1;
            }

            if (s == e) {
                cout << "! " << s << '\n';
                cout.flush();
                break;
            }
        }


    }

    return 0;
}