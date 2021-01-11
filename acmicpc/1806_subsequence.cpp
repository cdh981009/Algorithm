// 1806: Subsequence
// https://www.acmicpc.net/problem/1806
#include <bits/stdc++.h>

using namespace std;

#define INF (2e9 + 1)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e5;

int n, s;
int arr[N];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> s;
    FOR(i, 0, n) {
        cin >> arr[i];
    }

    int l, r;
    int minLen = INF;
    int sum = arr[0];
    
    l = r = 0;

    while (l <= r) {
        if (sum >= s) {
            minLen = min(minLen, r - l + 1);
            sum -= arr[l];
            ++l;
        } else {
            ++r;
            if (r >= n)
                break;
            sum += arr[r];
        }
    }

    cout << ((minLen == INF) ? 0 : minLen) << '\n';

    return 0;
}