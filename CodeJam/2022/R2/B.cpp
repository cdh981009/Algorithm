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

ll n;
vector<vector<bool>> v;

ll drawFill(ll r) {
    ll cnt = 0;
    v = vector<vector<bool>>(2 * r  + 1, vector<bool>(2 * r + 1, false));

    rep_(x, -r, r) {
        ll rx = x + r;
        rep_(y, -r , r) {
            ll ry = y + r;

            if (round(sqrt(x * x + y * y)) <= r) {
                v[rx][ry] = true;
            }
        }
    }

    rep_(x, 0, 2 * r) {
        rep_(y , 0, 2 * r) {
            if (v[x][y]) cnt++;
        }
    }

    return cnt;
}

void drawPer(ll r, ll ro) {
    rep_(x, -r, r) {
        ll rx = x + r;
        ll y = round(sqrt(r * r - x * x));

        v[x + ro][y + ro] = true;
        v[x + ro][-y + ro] = true;
        v[y + ro][x + ro] = true;
        v[-y + ro][x + ro] = true;
    }
}

ll drawWrong(ll r) {
    v = vector<vector<bool>>(2 * r  + 1, vector<bool>(2 * r + 1, false));
    rep_(x, 0, r) {
        drawPer(x, r);
    }

    ll cnt = 0;

    rep_(x, 0, 2 * r) {
        rep_(y, 0, 2 * r) {
            if (v[x][y]) cnt++;
        }
    }

    return cnt;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    rep_(testcase, 1, tc) {
        cout << "Case #" << testcase << ": ";

        ll ans = 0;

        cin >> n;

        ll df = drawFill(n);
        ll dw = drawWrong(n);
        //cout << df << ' ' << dw << '\n';
        ans = df - dw;

        cout << ans << '\n';
        // cout << brute(str) << '\n';
    }

    return 0;
}