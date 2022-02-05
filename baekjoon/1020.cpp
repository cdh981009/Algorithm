#include <bits/stdc++.h>

using namespace std;

#define INF 5e16
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;

constexpr int N = 1e5;
string str;
int n;
int cnt[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 5};
int scnt;
ll ex[16];
ll dp[15][150][2];

ll getDp(int ind, int target, bool carry) {
    if (ind == n)
        return target == 0 ? 0 : INF;
    if (target <= 0)
        return INF;

    ll& ref = dp[ind][target][carry];
    if (ref != -1)
        return ref;

    ref = INF;

    int curr = str[ind] - '0' + carry;
    bool co = false;

    if (curr == 10) {
        curr = 0;
        co = true;
    }

    FOR(i, 0, 10) {
        bool ncarry = false;
        ll sec = i - curr;

        if (i < curr) {
            ncarry = true;
            sec += 10;
        }

        ll res = sec + 10 * getDp(ind + 1, target - cnt[i], co || ncarry);
        ref = min(ref, res);
    }

    return ref;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ex[0] = 1;
    FOR(i, 1, 16) {
        ex[i] = ex[i - 1] * 10LL;
    }

    cin >> str;
    reverse(str.begin(), str.end());
    n = str.size();
    FOR(i, 0, n) { 
        scnt += cnt[str[i] - '0'];
    }

    memset(dp, -1, sizeof(dp));

    ll ans = getDp(0, scnt, true) + 1;
    cout << ans << '\n';

    return 0;
}