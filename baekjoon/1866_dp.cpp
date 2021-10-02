// https://www.acmicpc.net/problem/1866
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 3010;

int n, t, h;
int arr[N];
int pre[N];
int dp[N];

int getDp(int s) {
    if (s >= n)
        return 0;
    int& ref = dp[s];
    if (ref != -1)
        return ref;
    ref = INF;
    auto sum = [](int s, int e) {
        if (e < s)
            return 0;
        return pre[e] - (s == 0 ? 0 : pre[s - 1]);
    };

    FOR(i, s, n) {
        // min cost for [s...i]
        // by truck
        int sm = sum(s, i);
        int x = t * sm;
        // by heli
        int y = h;
        int mid = (s + i) / 2;
        int midv = arr[mid];
        y += (midv * (mid - s + 1) - sum(s, mid)) * t;
        y += (sum(mid, i) - midv * (i - mid + 1)) * t;

        ref = min(min(x, y) + getDp(i + 1), ref);
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

    memset(dp, -1, sizeof(dp));

    cin >> n;
    FOR(i, 0, n) {
        cin >> arr[i];
    }
    cin >> t >> h;
    sort(arr, arr + n);
    pre[0] = arr[0];
    FOR(i, 1, n) {
        pre[i] = arr[i] + pre[i - 1];
    }
    cout << getDp(0) << '\n';

    return 0;
}