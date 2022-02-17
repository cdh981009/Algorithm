#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 4e5;
constexpr int M = 12;

using ll = long long;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int cnt1[30] = {
        0,
    };
    vector<int> a(n), b(n), aux(n);

    FOR(i, 0, n)
        cin >> a[i];
    FOR(i, 0, n) {
        cin >> b[i];
        FOR(j, 0, 30)
        if (b[i] & (1 << j)) cnt1[j]++;
    }

    int ans1 = 0, ans2 = 0;

    FOR(i, 0, 30) {
        int mask = (1 << (i + 1)) - 1;
        int mx1, mn1, mx0, mn0;
        mx1 = mx0 = -1;
        mn1 = mn0 = INT32_MAX;
        for (int& x : a) {
            if (x & (1 << i)) {
                ans1 = (ans1 + ((ll)(1 << i) * (cnt1[i])) % 1999) % 1999;
                mx1 = max(mx1, x & mask);
                mn1 = min(mn1, x & mask);
            } else {
                mx0 = max(mx0, x & mask);
                mn0 = min(mn0, x & mask);
            }
        }
        ans2 |= (1 << i);
        auto op = [&](int x, int y) {
            return (x + y) & (1 << i);
        };
        for (int& x : b) {
            if ((mx1 != -1 && (!op(x, mx1) || !op(x, mn1))) ||
                (mx0 != -1 && (!op(x, mx0) || !op(x, mn0)))) {
                ans2 ^= (1 << i);
                break;
            }
        }
    }

    cout << ans1 << ' ' << ans2 << '\n';

    return 0;
}