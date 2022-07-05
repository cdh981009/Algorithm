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

constexpr int N = 101010;
constexpr int M = 1e9 + 7;

ll n, m, k, q, ans;
ll arr[N], ind[N];

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
        cin >> n;
        rep(i, 0, n) {
            cin >> arr[i];
            ind[arr[i]] = i;
        }

        ll s, e;
        s = -1;
        e = INF;
        ll ans = 1;
        rep(i, 0, n) {
            int x, y;
            x = max(s, ind[i]);
            y = min(e, ind[i]);
            if (x == s && y == e) {
                ll cnt = s - e + 1 - i;

                ans = ans * cnt % M;
            }
            s = x;
            e = y;
        }

        cout << ans << '\n';
    }

    return 0;
}