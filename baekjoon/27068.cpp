#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 7)
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep_(i, a, b) for (int i = (a); i <= (b); ++i)
#define repr_(i, a, b) for (int i = (a); i >= (b); --i)
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

constexpr int N = 500;
constexpr int M = 100;

ll n, m, k, x, ans;
ll a[N][N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k >> x;
    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> a[i][j];
        }
    }

    ans = INT64_MAX;
    set<pair<ll, pii>> st;

    auto getdiff = [](int i, int j) {
        ll mxdiff = 0;
        rep(l, 0, 4) {
            int ii = "1012"[l] - '1' + i;
            int jj = "0121"[l] - '1' + j;

            if (ii < 0 || ii >= n || jj < 0 || jj >= m) continue;

            ll diff = a[ii][jj] - a[i][j];
            mxdiff = max(mxdiff, diff);
        }
        return mxdiff;
    };

    rep(i, 0, n) {
        rep(j, 0, m) {
            st.insert({-getdiff(i, j), {i, j}});
        }
    }

    while (true) {
        if (st.empty()) {
            ans = 0;
            break;
        }

        auto [diff, p] = *st.begin();
        auto [i, j] = p;
        st.erase(st.begin());

        if (getdiff(i, j) != -diff) { // ignore this
            continue;
        }

        ans = min(ans, -diff);
        
        if (k == 0) break;

        a[i][j] = x;
        k--;
        rep(l, 0, 4) {
            int ii = "1012"[l] - '1' + i;
            int jj = "0121"[l] - '1' + j;

            if (ii < 0 || ii >= n || jj < 0 || jj >= m) continue;

            ll diff = a[i][j] - a[ii][jj];
            st.insert({-diff, {ii, jj}}); // update neighbor
        }
    }

    cout << ans << '\n';

    return 0;
}