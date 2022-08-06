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

constexpr int N = 301010;
constexpr int M = 8e6 + 10;

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

        ll cnt, n, k, cost;
        cin >> n >> k;
        vll a(n);

        ll mv = INT32_MAX;
        ll l, r;

        rep(i, 0, n) {
            cin >> a[i];
            mv = min(mv, a[i]);
        }
        
        cnt = k - mv;

        // special case
        if (cnt <= 0) {
            cout << 0 << ' ' << 0 << '\n';
            continue;
        }

        // normal case
        map<int, int> mni, mxi;
        l = -1;
        rep(i, 0, n) {
            int x = a[i];
            if (x == mv) {
                if (l == -1) l = i;
                r = i;
            }
            mxi[x] = i;

            if (!mni.count(x))
                mni[x] = i;
        }
        
        a.push_back(k);
        sort(a.begin(), a.end());
        int usz = unique(a.begin(), a.end()) - a.begin();
        int it = 0;
        
        cost = 0;
        while (true) {
            it++;
            if (it >= usz) break;
            int nxt = a[it];
            ll nl, nr;
            nl = mni[nxt];
            nr = mxi[nxt];

            nxt = min(nxt, (int)k);
            cost += (r - l + 1) * (nxt - mv);

            mv = nxt;
            if (mv == k) break;
            l = min(l, nl);
            r = max(r, nr);
        }

        cout << cnt << ' ' << cost << '\n';
    }

    return 0;
}