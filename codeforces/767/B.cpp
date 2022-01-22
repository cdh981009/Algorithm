#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 1e5;

int l, r, k;

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
        cin >> l >> r >> k;
        bool pos = true;
        if (k == 0) {
            if (l == r && l != 1)
                pos = true;
            else
                pos = false;
        } else {
            ll x = (2 * k + l - 1);
            //cout << x << '\n';
            if (x >= r || (r % 2 == 0 && r - 1 == x))
                pos = true;
            else pos = false;
        }

        cout << (pos ? "YES" : "NO") << '\n';
    }
    return 0;
}