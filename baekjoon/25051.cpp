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

constexpr int N = 110;
constexpr int M = 8e6 + 10;
constexpr int B = 4e6;

struct Star {
    ll x, y;
    ll s, dist, q, u, d;

    Star(ll _x, ll _y, ll _s) {
        x = _x;
        y = _y;
        dist = x * x + y * y;
        s = _s;

        if (x == 0) {
            q = y > 0 ? 1 : 3;
        } else if (y == 0) {
            q = x > 0 ? 0 : 2;
        } else {
            if (x * y > 0) {
                q = x > 0 ? 0 : 2;
            } else {
                q = x > 0 ? 3 : 1;
            }
        }

        u = abs(y);
        d = abs(x);
        if (q == 1 || q == 3) swap(u, d);
    }

    bool operator<(const Star& o) {
        if (q != o.q) return q < o.q;
        else return u * o.d < o.u * d;
    }
};

vector<Star> stars;
vll ps;
ll ans;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    rep(i, 0, n) {
        ll x, y, s;
        cin >> x >> y >> s;
        stars.emplace_back(x, y, s);
    }
    sort(stars.begin(), stars.end());

    rep(i, 0, n) {
        if (stars[i].q == 0) {
            stars.push_back(stars[i]);
            stars.back().q = 4;
        } else {
            break;
        }
    }

    rep(i, 0, m) {
        ll p;
        cin >> p;
        ps.push_back(p);
    }

    ans = INT64_MIN;

    //

    for (auto p : ps) {
        ll sum = 0;
        ll mxsum = 0;

        int j = 0;
        rep(i, 0, n) {
            auto &pivot = stars[i];
            auto end = Star(-pivot.y, pivot.x, 0);
            if (end.q == 0) end.q = 4;

            while (true) {
                if (j >= stars.size() || end < stars[j])
                    break;

                if (p >= stars[j].dist)
                    sum += stars[j].s;

                j++;
            }

            mxsum = max(sum, mxsum);
            //cout << mxsum << '\n';

            if (p >= pivot.dist)
                sum -= pivot.s;
        }

        ans = max(ans, mxsum - p);
    }
    //

    cout << ans << '\n';

    return 0;
}