#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 1e6;
constexpr int L = 6;
constexpr int M = 998244353;

int ten[6] = {10, 100, 1000, 10000, 100000, 1000000};

ll dp[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);

    ll ans = 0;

    auto check = [](int x) {
        while (x) {
            int a = x % 10;
            if (a >= 5) return 0;
            x /= 10;
        }
        return 1;
    };

    FOR(i, 0, n) {
        int x; cin >> x;
        a[i] = x;
        dp[x]++;
    }

    FOR(i, 0, L) {
        int t = ten[i];
        FOR(j, 0, N) {
            int d = j % t;
            if (d < 9 * (t / 10)) {
                dp[j + t / 10] += dp[j];
            }
        }
    }

    FOR(i, 0, n) {
        int x = N - a[i] - 1;
        ans += dp[x];
        ans -= check(a[i]);
    }


    cout << ans / 2 << '\n';

    return 0;
}