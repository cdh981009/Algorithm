#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 110;

int n, x, t;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n >> x >> t;
        long long k = min(n - 1, t / x);
        long long ans = 0;
        ans = (k * (k + 1)) / 2 + k * (n - k - 1);

        cout << ans << '\n';
    }
    return 0;
}