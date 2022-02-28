#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 100;
constexpr int M = 998244353;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int f, p;
    int mx = 0;
    ll sm = 0;
    FOR(i, 0, n) {
        int x; cin >> x;
        if (i == 0) {
            f = x;
        } else {
            sm += abs(x - p);
            if (i == n - 1)
                sm += abs(x - f);
        }
        mx = max(x, mx);
        p = x;
    }
    sm /= 2;

    cout << max((ll)mx, sm) << '\n';

    return 0;
}