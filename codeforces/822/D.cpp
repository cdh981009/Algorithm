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

constexpr int N = 201010;
constexpr int M = 100;

ll n, m, k, q, ans;
ll a[N];

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
        cin >> n >> k;
        k--;
        bool pos = false;

        rep(i, 0, n) cin >> a[i];
        vector<ll> v1, v2;
        rep(i, 0, k) {
            v1.push_back(a[i]);
        }
        repr_(i, n - 1, k + 1) {
            v2.push_back(a[i]);
        }
        ll x = a[k];

        ll s1, s2;

        s1 = s2 = 0;

        while (!v1.empty() && !v2.empty()) {
            while (!v1.empty() && s1 + v1.back() >= -x) {
                s1 += v1.back();
                v1.pop_back();
                if (s1 > 0) {
                    x += s1;
                    s1 = 0;
                }
            }

            while (!v2.empty() && s2 + v2.back() >= -x) {
                s2 += v2.back();
                v2.pop_back();
                if (s2 > 0) {
                    x += s2;
                    s2 = 0;
                }
            }

            if (!v1.empty() && !v2.empty() && s1 + v1.back() < -x && s2 + v2.back() < -x) {
                break;
            }
        }

        if (v1.empty() || v2.empty()) pos = true;

        printYN(pos);
    }

    return 0;
}