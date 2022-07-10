#include <bits/stdc++.h>

using namespace std;

#define INF INT64_MAX
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

constexpr int N = 1030;
constexpr int M = 100;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    for (int testcase = 1; testcase <= tc; ++testcase) {
        cout << "Case #" << testcase << ": ";

        ll n, m, k, sum;
        vector<ll> a, b, pa, pb;
        cin >> n;
        a.resize(n);
        pa.resize(n);
        sum = 0;
        rep(i, 0, n) {
            cin >> a[i];
            sum += a[i];
            pa[i] = a[i] + (i == 0 ? 0 : pa[i - 1]);
        }
        cin >> m;
        b.resize(m);
        pb.resize(m);
        rep(i, 0, m) {
            cin >> b[i];
            sum += b[i];
            pb[i] = b[i] + (i == 0 ? 0 : pb[i - 1]);
        }

        auto rs = [](vector<ll>& vec, int l, int r) {
            return vec[r] - (l == 0 ? 0 : vec[l - 1]);
        };
        cin >> k;

        ll ans = INF;
        rep_(i, 0, n) {
            int alen = i;
            int blen = n + m - k - i;
            if (alen > n || blen > m || blen < 0) continue;
            ll res = 0;
            ll amin, bmin;
            amin = bmin = INF;
            if (alen == 0)
                amin = 0;
            else {
                rep_(j, 0, n) {
                    if (j + alen - 1 >= n) break;
                    amin = min(amin, rs(pa, j, j + alen - 1));
                }
            }

            if (blen == 0)
                bmin = 0;
            else {
                rep_(j, 0, m) {
                    if (j + blen - 1 >= m) break;
                    bmin = min(bmin, rs(pb, j, j + blen - 1));
                }
            }

            //cout << i << ' ' << amin << ' ' << bmin << '\n';

            res = amin + bmin;

            ans = min(res, ans);
        }

        cout << sum - ans << '\n';
    }

    return 0;
}