#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define fi first
#define se second
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (ll i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pii>;

constexpr int N = 1010100;
constexpr int M = 100;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        ll n, c;
        cin >> n >> c;
        vector<int> a(c + 10, 0);
        FOR(i, 0, n) {
            int x;
            cin >> x;
            a[x] = 1;
        }

        FOR_(i, 1, c) {
            a[i] += a[i - 1];
        }

        auto exists = [&](int x) {
            return a[x] - a[x - 1] == 1;
        };

        auto exist = [&](ll l, ll r) {
            l = min(l, c);
            r = min(r, c);
            return (a[r] != a[l - 1]);
        };

        bool pos = true;
        if (!a[1]) {
            pos = false;
        } else {
            FOR_(i, 2, c) {
                if (!exists(i)) {
                    FOR_(j, 2, c / i) {
                        if (exists(j)) {
                            ll l = (ll)j * i;
                            ll r = (ll)j * (i + 1) - 1;
                            if (l <= c && exist(l, r)) {
                                pos = false;
                                break;
                            }
                        }
                    if (!pos) break;
                    }
                }
                if (!pos) break;
            }

        }

        cout << (pos ? "Yes" : "No") << '\n';
    }

    return 0;
}