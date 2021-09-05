#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 10;

int n;
string str;
ll ans;

ll solve(int ind, bool getCarry, bool pushCarry) {
    if (ind >= n)
        return (getCarry || pushCarry) ? 0 : 1;

    int x = str[ind] - '0';
    int target = x;

    if (pushCarry)
        target = x + 10;
    if (getCarry)
        target -= 1;

    if (target < 0 || target >= 19)
        return 0;

    ll ret = 0;

    if (target >= 10) {
        int mx = 9;
        int mn = target - mx;
        ret = mx - mn + 1;
    } else {
        ret = target + 1;
    }

    ret *= (solve(ind + 2, false, getCarry) + solve(ind + 2, true, getCarry));

    return ret;
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
        ans = 0;
        cin >> str;
        n = str.size();
        ll x = (solve(0, true, false) + solve(0, false, false));
        ll y = (solve(1, true, false) + solve(1, false, false));
        ans = x * y;
        ans -= 2;
        cout << ans << '\n';
    }
    return 0;
}