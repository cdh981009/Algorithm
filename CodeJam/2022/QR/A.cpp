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
        int r, c; cin >> r >> c;

        cout << "Case #" << testcase << ':';
        cout << '\n';

        rep(i, 0, 2 * r + 1) {
            rep(j, 0, 2 * c + 1) {
                bool p = !((i + j) % 2);
                if (i < 2 && j < 2) cout << '.';
                else if (p) {
                    if (i % 2)
                        cout << '.';
                    else
                        cout << '+';
                } else {
                    if (i % 2)
                        cout << '|';
                    else
                        cout << '-';
                }
            }
            cout << '\n';
        }
    }


    return 0;
}