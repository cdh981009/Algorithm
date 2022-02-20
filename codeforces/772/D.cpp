#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 201010;
constexpr int M = 1e9 + 7;

ll dp[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));

    ll ans = 0;
    int n, p; cin >> n >> p;
    vector<ll> a(n);
    set<ll> s;
    FOR(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());

    // deleting duplicates
    FOR(i, 0, n) {
        ll x = a[i];
        ll y = x;
        bool u = true;
        while (y) {
            if (y % 2) {
                y /= 2;
            } else if (y % 4 == 0) {
                y /= 4;
            } else {
                break;
            }
            if (s.count(y) > 0) {
                u = false;
                break;
            }
        }
        if (u) {
            s.insert(x);
        }
    }

    dp[0] = 1;
    dp[1] = 2;

    FOR(x, 2, N) {
        dp[x] = dp[x - 1] + dp[x - 2] + 1;
        dp[x] %= M;
    }

    for (auto &x : s) {
        int i = 0;
        while (true) {
            if (x < (1LL << i)) break;
            i++;
        }
        //cout << p - i << ' ';
        ans += (p - i >= 0 ? dp[p - i] : 0);
        ans %= M;
    }

    cout << ans << '\n';

    return 0;
}