#include <bits/stdc++.h>

using namespace std;

#define INF (1e9+7)
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
        rep(i, 0, n) {
            cin >> a[i];
        }
        rep(i, 0, n) {
            cin >> b[i];
        }

        rep(i, 0, n) {
            auto it = lower_bound(b, b + n, a[i]);
            cout << *it - a[i] << ' ';
        }
        cout << '\n';

        int j = 0;
        rep(i, 1, n) {
            if (a[i] > b[i - 1]) {
                while (j < i) {
                    cout << b[i - 1] - a[j] << ' ';
                    j++;
                }
            }
        }
        while (j < n) {
            cout << b[n - 1] - a[j] << ' ';
            j++;
        }
        cout << '\n';
    }

    return 0;
}