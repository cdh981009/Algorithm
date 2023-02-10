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
        int i = 0;
        int ii = 1;
        int x, y;
        x = 0;
        y = 0;
        while (n > 0) {
            int z = n % 10;
            n /= 10;

            int xx, yy;

            xx = yy = z / 2;

            if (z % 2 == 1) {
                if (i % 2) {
                    xx++;
                } else {
                    yy++;
                }
                
                i++;
            }
            x += ii * xx;
            y += ii * yy;

            ii *= 10;
        }

        cout << x << ' ' << y << '\n';
    }

    return 0;
}