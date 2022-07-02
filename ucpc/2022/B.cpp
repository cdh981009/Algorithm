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

constexpr int N = 201010;
constexpr int M = 100;

int n, m, k, q, ans;
int arr[N];

vector<char> v;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    struct Line {
        int x1, y1, x2, y2, w;
        bool operator<(Line &o) {
            return this->w < o.w;
        };
    };

    vector<Line> lines;
    rep(i, 0, n) {
        int x1, y1, x2, y2, w;
        cin >> x1 >> y1 >> x2 >> y2 >> w;
        lines.push_back({x1, y1, x2, y2, w});
    }
    sort(lines.begin(), lines.end());

    ll ans = 0;

    auto op = [&](const auto &l, const auto &r) {
        auto op2 = [&](const auto &l, const auto &r) {
            bool res = false;

            auto cross = [&](ll x1, ll y1, ll x2, ll y2) {
                return (x1 * y2 - x2 * y1) > 0 ? 1 : -1;
            };

            res = cross(l.x2 - l.x1, l.y2 - l.y1, r.x1 - l.x1, r.y1 - l.y1) !=
                  cross(l.x2 - l.x1, l.y2 - l.y1, r.x2 - l.x1, r.y2 - l.y1);
            return res;
        };

        return op2(l, r) && op2(r, l);
    };

    rep(i, 0, n) {
        ans += lines[i].w;
        rep(j, i + 1, n) {
            if (op(lines[i], lines[j])) ans += lines[i].w;
        }
    }

    cout << ans << '\n';

    return 0;
}