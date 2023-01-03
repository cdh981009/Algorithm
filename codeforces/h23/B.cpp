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

constexpr int N = 300;
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
        if (n % 2 == 0) {
            cout << "YES\n";
            rep(i, 0, n) {
                cout << (i % 2 ? +1 : -1) << ' ';
            }
            cout << '\n';

        } else {
            if (n == 3)
                cout << "NO\n";
            else {
                cout << "YES\n";
                int x = n / 2 - 1;
                int y = (n + 1) / 2 - 1;
                y *= -1;
                rep(i, 0, n) {
                    if (i % 2 == 0)
                        cout << x << ' ';
                    else
                        cout << y << ' ';
                }
                cout << '\n';
            }
        }
    }

    return 0;
}