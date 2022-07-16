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

constexpr int N = 301010;
constexpr int M = 8e6 + 10;

ll n, m;
vpii a, b;
vi c;
ll ans;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    rep(tc, 0, T) {
        cout << "Case #" << tc + 1 << '\n';
        ans = 0;

        cin >> n;
        a = vpii(n);
        c = vi(n);
        rep(i, 0, n) {
            cin >> a[i].second;
            c[i] = a[i].second;
        }
        rep(i, 0, n) cin >> a[i].first;

        sort(a.begin(), a.end(), [](const pii& l, const pii& r) {
            return l.first != r.first ? l.first < r.first : l.second < r.second;            
        });
        
        rep(i, 0, n) {
            ans += abs(c[i] - a[i].second);
        }

        cout << ans << '\n';
    }

    return 0;
}