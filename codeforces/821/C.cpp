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

constexpr int N = 101010;
constexpr int M = 100;

ll n, m, k, q;
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
        cin >> n;
        rep(i, 0, n) cin >> a[i];
        vector<pair<int, int>> ans;

        int p = a[0] % 2;

        if (n > 1) {
            if (a[0] % 2 == a[n - 1] % 2) {
                ans.push_back({1, n});
                rep(i, 1, n - 1) {
                    if (p == a[i] % 2) {
                        ans.push_back({i + 1, n});
                    } else {
                        ans.push_back({1, i + 1});
                    }
                }
            } else {
                ans.push_back({1, n});
                rep(i, 1, n - 1) {
                    if (p == a[i] % 2) {
                        ans.push_back({i + 1, n});
                    } else {
                        ans.push_back({1, i + 1});
                    }
                }
            }
        }

        cout << ans.size() << '\n';
        rep(i, 0, ans.size()) {
            cout << ans[i].first << ' ' << ans[i].second << '\n';
        }
    }

    return 0;
}