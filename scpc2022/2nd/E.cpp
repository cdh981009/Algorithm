#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 7)
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep_(i, a, b) for (int i = (a); i <= (b); ++i)
#define repr_(i, a, b) for (int i = (a); i >= (b); --i)
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

constexpr int N = 64;
constexpr int M = 998244353;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    rep(tc, 0, T) {
        cout << "Case #" << tc + 1 << '\n';

        ll n, k;
        cin >> n >> k;
        vll a(n), b(n);
        ll p = 0;

        rep(i, 0, n) {
            cin >> a[i];
            p += a[i];
            p %= M;
        }
        rep(i, 0, n) {
            a[i] = (p - a[i] + M) % M;
            b[i] = a[i];
        }

        ll ans = p;
        ll pp = p;
        rep(j, 1, k) {
            ll sum = 0;
            rep(i, 0, n) {
                b[i] = (b[i] * a[i]) % M;
                sum = (sum + b[i]) % M;
            }
            
            pp = pp * p % M;

            sum = (n * pp % M - sum + M) % M;

            ans ^= sum;
        }

        cout << ans << endl;
    }

    return 0;
}