// 1644: Sum of Consecutive Prime Numbers
// https://www.acmicpc.net/problem/1644
#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 1)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 30;
constexpr int M = 1 << 15;

int n, c;
int arr[N];

// 최대 2^15 가지의 가능한 sum 가짓수들
int sums[1 << 15];
int sCnt;

int ans = 0;

void getSum(int i, int sum, int end) {
    if (i == end) {
        if (end == n) {
            auto it = upper_bound(sums, sums + sCnt, c - sum);
            int x = (it - sums);
            ans += x;
        } else {
            sums[sCnt++] = sum;
        }
    } else {
        getSum(i + 1, sum, end);
        if (sum + arr[i] <= c)
            getSum(i + 1, sum + arr[i], end);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> c;
    FOR(i, 0, n) {
        cin >> arr[i];
    }

    getSum(0, 0, n / 2);
    sort(sums, sums + sCnt);
    getSum(n / 2, 0, n);

    cout << ans << '\n';

    return 0;
}