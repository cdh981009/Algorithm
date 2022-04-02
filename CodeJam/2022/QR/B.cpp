#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 10)
#define fi first
#define se second
#define rep(i, a, b) for (ll i = (a); i < (b); ++i)
#define rep_(i, a, b) for (ll i = (a); i <= (b); ++i)
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (ll i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pii>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 2001;
constexpr int M = 100;

ll n, k, m, ans;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    rep_(testcase, 1, tc) {
        cout << "Case #" << testcase << ": ";

        int mn[4];
        
        rep(i, 0, 4) mn[i] = 1e7;

        rep(i, 0, 3)
            rep(j, 0, 4) {
                int x;
                cin >> x;
                mn[j] = min(mn[j], x);
            }

        int ans[4];
        int tt = 1000000;
        bool pos = true;

        rep(i, 0, 4) {
            ans[i] = min(tt, mn[i]);
            tt -= ans[i];
        }
        if (tt > 0) pos = false;

        if (!pos) {
            cout << "IMPOSSIBLE\n";
        } else {
            rep(i, 0, 4) {
                cout << ans[i] << ' ';
            }
            cout <<'\n';
        }

        
    }


    return 0;
}