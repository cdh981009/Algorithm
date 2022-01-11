#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;

constexpr int N = 25e4;
int n, c;
ll arr[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll ans = INT64_MAX;
    int ansi;

    cin >> n >> c;
    FOR(i, 0, n) {
        cin >> arr[i];
    }

    ll l, r;
    l = r = 0;
    FOR(i, 0, n - 1) {
        r += (arr[i + 1] - arr[i] + c) % c;
    }

    FOR(i, 0, n) {
        ll res = max(l, r);

        if (res < ans) {
            ans = res;
            ansi = i;
        }

        if (i + 1 < n) {
            r -= (arr[i + 1] - arr[i] + c) % c;
            l += (arr[i] - arr[i + 1] + c) % c;
        }
    }

    cout << ansi + 1 << '\n' << ans << '\n';
    return 0;
}