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

ll n, m;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    cin >> n >> m;
    bool pos = true;

    ll prev = 1;
    rep(i, 0, n - 1) {
        int x; cin >> x;

        int c1, c2;
        char d1, d2;

        if (x == 1) {
            cin >> c1 >> d1;
        } else if (x == 2) {
            cin >> c1 >> d1 >> c2 >> d2;    
        }

        if (prev > m) pos = false;
        if (!pos) continue;

        if (x == 1) {
            if (d1 == 'R') {
                if (prev >= c1) pos = false;
            } else {
                prev = max(prev, c1 + 1LL);
            }
        } else if (x == 2) {
            if (d1 == d2) {
                if (d1 == 'R') { // -->
                    if (prev >= c1) pos = false;
                } else { // <<-
                    prev = max(prev, c2 + 1LL);
                }
            } else {
                if (d1 == 'L') { // <-  ->
                    if (c1 + 1 == c2) pos = false;
                    else if (prev >= c2) pos = false;
                    else prev = max(prev, c1 + 1LL);
                } else { // -><-
                    if (prev >= c1) {
                        if (prev <= c2) prev = c2 + 1;
                    }
                }
            }
        }
    }

    if (prev > m) pos = false;

    printYN(pos);

    return 0;
}