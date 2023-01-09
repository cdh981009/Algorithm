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
        cin >> n;
        vector<ll> check(n + 10, 0);
        rep(i, 0, n) cin >> a[i];
        rep(i, 0, n) cin >> b[i];

        rep(i, 0, n) {
            if (a[i] > b[i]) {
                check[b[i]] += 1;
                check[a[i]] -= 1;
            }
        }

        rep_(i, 1, n) {
            check[i] += check[i - 1];
        }

        vector<int> ans;
        rep_(i, 1, n) {
            bool pos = true;
            for (int j = i; j <= n; j += i) {
                if (check[j] > 0) pos = false;
            }
            if (pos) ans.push_back(i);
        }

        cout << ans.size() << '\n';
        rep(i, 0, ans.size()) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}