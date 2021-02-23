#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 5001;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long a, b, c, p;
    int tc; cin >> tc;
    while (tc--) {
        long long ans = INT64_MAX;
        cin >> p >> a >> b >> c;
        long long k;
        k = ((p + a - 1) / a);
        ans = min(ans, (k * a) - p);
        k = ((p + b - 1) / b);
        ans = min(ans, (k * b) - p);
        k = ((p + c - 1) / c);
        ans = min(ans, (k * c) - p);
        cout << ans << '\n';
    }
    return 0;
}