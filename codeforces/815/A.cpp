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
ll a[N];

ll gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }

    return a;
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
        ll a, b, c, d;
        ll ans = 2;
        cin >> a >> b >> c >> d;
        if (a == 0 && c == 0)
            ans = 0;
        else {
            if (a == 0 || c == 0) {
                ans = 1;
            } else {
                if (a * d == c * b) ans = 0;
                else if ((a * d) % (c * b) == 0 ||
                    (c * b) % (a * d) == 0)
                        ans = 1;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}