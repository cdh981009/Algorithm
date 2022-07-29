#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 7)
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

constexpr int N = 101010;
constexpr int M = 1010100;

ll n, k;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    ll res = -1;
    ll ans;

    ll x = 0;
    ll y = 0;
    ll sq = sqrt(n);

    ll cnt = 0;

    // dump
    cout << "? " << 1 << '\n';
    cout.flush();
    cin >> res;

    while (true) {
        cout << "? " << x + 1 << '\n';
        cout.flush();

        cin >> res;
        if (res != k) {
            break;
        }

        cnt++;
        if (cnt > sq + 1) {
            cnt = 0;
            y += 1;
        }

        x = cnt * sq + y;
        x %= n;
    }

    if (res > k) {
        while (true) {
            x--;
            x = (x + n) % n;
            cout << "? " << x + 1 << '\n';
            cout.flush();
            cin >> res;
            if (res == k) {
                ans = x + 1;
                break;
            }
        }
    } else {
        while (true) {
            x++;
            x = x % n;
            cout << "? " << x + 1 << '\n';
            cout.flush();
            cin >> res;
            if (res == k) {
                ans = x + 1;
                break;
            }
        }
    }

    cout << "! " << ans << '\n';

    return 0;
}