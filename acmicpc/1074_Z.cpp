// 1074: Z
// https://www.acmicpc.net/problem/1074
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int num = (1 << n);
    int r, c;
    cin >> r >> c;

    int ans = 0;
    while (num >= 2) {
        if (r >= num / 2) {
            if (c >= num / 2) {
                ans += ((num * num) >> 2) * 3;
            } else {
                ans += ((num * num) >> 2) * 2;
            }
        } else {
            if (c >= num / 2) {
                ans += ((num * num) >> 2) * 1;
            }
        }

        num /= 2;
        r %= num;
        c %= num;
    }

    cout << ans << '\n';

    return 0;
}