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

constexpr int N = 5010;
constexpr int M = 100;

ll n, x, y, d;
vector<int> a, b;
vector<int> vec;
vector<vector<ll>> dp;

ll getDp(int s, int e) {
    if (s > e) return 0;

    auto &ref = dp[s][e];
    if (ref != -1) return ref;

    ref = INT64_MAX;

    auto op = [&](int i, int j) {
        ll len = vec[j] - vec[i];
        return min(len * x, y);
    };

    ref = min(ref, op(s, s + 1) + getDp(s + 2, e));
    ref = min(ref, op(e - 1, e) + getDp(s, e - 2));
    ref = min(ref, op(s, e) + getDp(s + 1, e - 1));

    return ref;
}

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
        cin >> n >> x >> y;
        a.clear();
        b.clear();
        rep(i, 0, n) {
            char c;
            cin >> c;
            if (c == '1')
                a.push_back(1);
            else
                a.push_back(0);
        }
        rep(i, 0, n) {
            char c;
            cin >> c;
            if (c == '1')
                b.push_back(1);
            else
                b.push_back(0);
        }

        d = 0;
        vec.clear();
        rep(i, 0, n) {
            if (a[i] != b[i]) {
                d++;
                vec.push_back(i);
            }
        }

        dp = vector<vector<ll>>(d, vector<ll>(d, -1));

        if (d % 2) {
            cout << -1 << '\n';
        } else {
            if (d == 0)
                cout << 0 << '\n';
            else {
                ll ans = 0;
                if (x >= y) {
                    if (d == 2 && vec[0] + 1 == vec[1]) {
                        if (n == 3)
                            ans = x;
                        else
                            ans = min(2 * y, x);
                    } else {
                        ans = d / 2 * y;
                    }
                } else {
                    ans = getDp(0, d - 1);
                }

                cout << ans << '\n';
            }
        }
    }

    return 0;
}