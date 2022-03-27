#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 10)
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep_(i, a, b) for (int i = (a); i <= (b); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pii>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 101010;
constexpr int M = 100;

ll n, m, ans;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int l, r;
        cin >> l >> r;
        n = r - l + 1;
        vi a(n), b(n);
        rep(i, 0, n) cin >> a[i];
        rep(i, l, r + 1) b[i - l] = i;

        if (n % 2) { // odd
            int x = 0;
            int y = 0;
            rep_(i, l, r) {
                y ^= i;
                x ^= a[i - l]; 
            }
            ans = x ^ y;
        } else {
            ans = 0;
            for (int i = 16; i >= 0; --i) {
                int mask = ((1 << 17) - 1) - ((1 << i) - 1);
                sort(a.begin(), a.end(), [&](int l, int r) {
                    return (l & mask) < (r & mask);
                });

                sort(b.begin(), b.end(), [&](int l, int r) {
                    return (l & mask) < (r & mask);
                });

                bool c = false;
                rep(j, 0, n) {
                    if ((a[j] & mask) != (b[j] & mask)) {
                        c = true;
                        break;
                    }
                }
                if (c) {
                    ans |= (1<<i);
                    rep(j, 0, n) {
                        a[j] ^= (1<<i);
                    }
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}