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

constexpr int N = 51;
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
        cin >> n >> m;

        bool pos = false;
        if (n > m) {
            cout << "No\n";

        } else if (n % 2 == 1) {  // odd
            cout << "Yes\n";
            rep(i, 0, n) {
                if (i == 0) {
                    cout << m - n + 1 << ' ';
                } else
                    cout << 1 << ' ';
            }
            cout << '\n';
        } else {
            if (m % 2 == 1)
                cout << "No\n";

            else {
                cout << "Yes\n";
                rep(i, 0, n) {
                    if (i == 0 || i == 1) {
                        cout << (m - n + 2) / 2 << ' ';
                    } else {
                        cout << 1 << ' ';
                    }
                }
                cout << '\n';
            }
        }
    }

    return 0;
}