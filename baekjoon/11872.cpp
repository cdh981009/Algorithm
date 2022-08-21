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

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k, s;
    cin >> n;
    s = 0;

    // grundy number goes
    // 0 1 2 4 3 5 6 8 7 9 10 12 11 ..
    rep(i, 0, n) {
        ll x; cin >> x;
        if (x == 0) x = 0;
        else {
            if ((x + 1) / 2 % 2 == 0) {
                if (x % 2 == 0) x -= 1;
                else x += 1;
            }
        }
        s ^= x;
    }

    if (s == 0)
        cout << "cubelover\n";
    else
        cout << "koosaga\n";


    return 0;
}