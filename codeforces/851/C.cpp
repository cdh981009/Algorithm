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
        bool pos = false;
        ll x;
        if (n % 2 == 1) {
            pos = true;
            x = (3 * n + 3) / 2;

        }

        printYN(pos);

        if (pos) {
            rep_(i, 1, n) {
                if (i <= (n + 1) / 2) {
                    cout << i << ' ' << i + n + n / 2 << '\n';
                } else {
                    cout << i << ' ' << i + n - (n + 1) / 2 << '\n';
                }
            }
        }
    }
    return 0;
}