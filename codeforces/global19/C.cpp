#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 101010;

int n;
vector<ll> v;

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
        cin >> n;
        v = vector<ll>(n);
        bool allOne = true;
        ll ans = 0;
        FOR(i, 0, n) {
            cin >> v[i];
            if (i > 0 && i < n - 1) {
                if (v[i] != 1) allOne = false;

                if (v[i] % 2 == 0) {
                    ans += v[i] / 2LL;
                } else {
                    ans += (v[i] + 1LL) / 2LL;
                }
            }
        }

        if (allOne || (n == 3 && v[1] % 2 == 1)) {
            cout << -1 << '\n';
        } else {

            cout << ans << '\n';
        }
    }
    return 0;
}