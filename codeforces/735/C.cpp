#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 10;
int n, m;
int ans;

int solve(int x) {
    int p = (1 << x);
    int a = (n & p);
    int b = (m & p);

    if (x == 0) {
        return b ? 2 : (a ? 0 : 1);
    }

    int r = solve(x - 1);

    if (a && !b) {
        return 0;
    } else if (a && b) {
        if (r == p) {
            return p << 1;
        } else {
            return r;
        }
    } else if (!a && b) {
        if (r == p) {
            return p << 1;
        } else {
            return p + r;
        }
    } else {
        return r;
    }
}

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
        cin >> n >> m;

        ans = solve(30);

        cout << ans << '\n';
    }
    return 0;
}