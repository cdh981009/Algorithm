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

constexpr int N = 2000;
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
        ll x , y;
        cin >> n >> x >> y;

        bool pos = true;

        if (y == 0) swap(x, y);

        if (x * y != 0) {
            pos = false;
        } else if (x == 0 && y == 0) {
            pos = false;
        } else if ((n - 1) % y) {
            pos = false;
        }
        
        if (!pos) cout << -1 << '\n';
        else {
            int cnt = 0;
            int x = 2;
            rep(i, 1, n) {
                if (cnt == y) {
                    x = i + 1;
                    cnt = 0;
                }
                cnt++;
                cout << x << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}