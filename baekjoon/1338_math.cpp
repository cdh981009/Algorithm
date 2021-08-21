// https://www.acmicpc.net/problem/1338
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;

ll l, r, x, y;

void solve() {
    cin >> l >> r >> x >> y;
    
    if (l > r)
        swap(l, r);

    ll ans;
    bool pos = false;
    
    auto f = [&](ll n) {
        return n >= l && n <= r;
    };

    if (y >= 0 && y < abs(x)) {
        ll r = (l % x + x) % x;
        ans = l - r + y;
        if (f(ans) && !f(ans + x))
            pos = true;
    }

    if (pos)
        cout << ans << '\n';
    else
        cout << "Unknwon Number\n";
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}