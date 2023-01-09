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

constexpr int N = 501010;
constexpr int M = 100;

ll n, m, k, q, ans;
ll a[N], b[N];

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
        cin >> n >> m;
        vpll vec;
        rep(i, 0, n) {
            ll a;
            cin >> a;
            vec.push_back({a, i});
        }

        sort(vec.begin(), vec.end());

        vector<ll> where(n);
        rep(i, 0, n) {
            where[vec[i].second] = i;
        }

        int x = 1;
        int mx = n;

        auto op = [&](int x) {
            ll man = n - x;
            // win x-th man and win other x - 1 guys
            int w = where[man];
            ll rem = m - vec[w].first;

            if (rem >= 0) {
                ll cnt = 1;
                rep(i, 0, n) {
                    if (i == w) continue;
                    if (rem >= vec[i].first) {
                        rem -= vec[i].first;
                        cnt++;
                    } else {
                        break;
                    }
                }
                if (cnt >= man) return true;
            }

            // lose to x-th man win other x + 1 guys

            rem = m;
            ll cnt = 0;

            rep(i, 0, n) {
                if (rem >= vec[i].first) {
                    rem -= vec[i].first;
                    cnt++;
                } else {
                    break;
                }
            }

            if (cnt >= man + 1) return true;

            return false;
        };

        // is it possible to win x-th or lower place?
        for (int step = mx; step >= 1; step /= 2) {
            while (x + step <= mx && op(x + step) == false) {
                x += step;
            }
        }

        if (op(x) == false)
            x++;

        cout << x << '\n';
    }

    return 0;
}