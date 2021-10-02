// https://www.acmicpc.net/problem/1866
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 20;

bool arr[N][N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            char x; cin >> x;
            arr[i][j] = (x == 'H' ? 1 : 0);
        }
    }

    int ans = n * n;
    FOR(i, 0, 1 << n) {
        int h = 0;
        FOR(j, 0, n) {
            int cnt = 0;
            FOR(k, 0, n) {
                cnt += ((i & (1 << k)) ? 1 : 0) ^ (arr[j][k]);
            }
            if (cnt > n / 2)
                cnt = n - cnt;
            h += cnt;
        }
        ans = min(h, ans);
    }

    cout << ans << '\n';

    return 0;
}