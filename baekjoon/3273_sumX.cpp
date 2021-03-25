// 3273: SumX
// https://www.acmicpc.net/problem/3273
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e5;

int arr[N];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    FOR(i, 0, n) {
        cin >> arr[i];
    }
    int x; cin >> x;
    sort(arr, arr + n);

    int l = 0;
    int r = n - 1;

    long long cnt = 0;
    while (l < r) {
        if (arr[l] + arr[r] == x) {
            cnt++;
        }
        if (arr[l] + arr[r] >= x) {
            r--;
        } else {
            l++;
        }
    }

    cout << cnt << '\n';

    return 0;
}