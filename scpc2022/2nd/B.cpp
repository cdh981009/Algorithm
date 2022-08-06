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

struct Bit {
    vi vec;

    Bit(int n) {
        vec = vi(n + 1, 0);
    }

    void update(int i, int v) {
        i++;
        while (i < vec.size()) {
            vec[i] += v;
            i += (i & -i);
        }
    }

    int query(int i) {
        i++;
        int res = 0;
        while (i) {
            res += vec[i];
            i -= (i & -i);
        }
        return res;
    }
};

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

        int n; cin >> n;
        ll ans = 0;
        vector<vector<int>> inds(n + 1);
        vi vec(n);
        Bit bit(n);

        rep(i, 0, n) {
            int x;
            cin >> x;
            vec[i] = x;
            inds[x].push_back(i);
        }

        rep(i, 0, n) {
            int x = vec[i];
            int y = inds[x].back();
            if (i >= y) continue;
            inds[x].pop_back();

            ans += y - i;
            ans -= bit.query(y) - (i == 0 ? 0 : bit.query(i - 1));

            bit.update(i, 1);
            bit.update(y, 1);
        }

        cout << ans << '\n';
    }

    return 0;
}