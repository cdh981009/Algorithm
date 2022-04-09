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

ll n, k, m, ans;

int main() {
#ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    rep_(testcase, 1, tc) {
        cin >> n;
        vector<ll> v, b;
        FOR_(i, 0, 29) {
            b.push_back(1 << i);
        }
        FOR(i, 0, 70) {
            v.push_back(1000000000 - i);
        }
        
        for (auto x : v) {
            cout << x << ' ';
        }
        for (auto x : b) {
            cout << x << ' ';
        }
        cout << '\n';
        cout.flush();

        FOR(i, 0, n) {
            ll x; cin >> x;
            v.push_back(x);
        }        
        sort(v.begin(), v.end());
        ll t = 0;
        FOR_(i, 0, 29) t += b[i];
        for (auto x : v) {
            t += x;
        }
        t /= 2;

        vector<ll> ans;
        int i = v.size() - 1;
        while (true) {
            ll x = v[i--];
            if (t - x < 0) break;
            else {
                t -= x;
                ans.push_back(x);
            }
        }

        rep_(i, 0, 30) {
            if (t & (1 << i)) {
                ans.push_back((1 << i));
            }
        }

        for (auto x : ans) {
            cout << x << ' ';
        }
        cout << '\n';
        cout.flush();
    }


    return 0;
}