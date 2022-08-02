#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 10)
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep_(i, a, b) for (int i = (a); i <= (b); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pii>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 101010;
constexpr int M = 100;

ll n, m, ans, k;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        vector<vll> c(n, vll(m));

        ll sss = -1;
        rep(i, 0, n) {
            ll s = 0, ss = 0;
            rep(j, 0, m) {
                ll x;
                cin >> x;
                s += x;
                ss += s;
            }

            if (i == 0) {
                sss = ss;
            } else {

                if (sss != ss) {
                    if (sss < ss) {
                        ans = 1;
                        k = ss - sss;
                    } else {
                        ans = i + 1;
                        k = sss - ss;
                    }

                }
            }
        }


        cout << ans << ' ' << k << '\n';
    }

    return 0;
}