// 2470: 두 용액
// https://www.acmicpc.net/problem/2470
#include <bits/stdc++.h>

using namespace std;

#define INF (2e9 + 1);
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e5;

int n;
int arr[N];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 0, n) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    int l, r, ansL, ansR;
    int minVal = INF;
    
    l = 0;
    r = n - 1;

    while (l < r) {
        int s = arr[l] + arr[r];
        if (minVal > abs(s)) {
            minVal = abs(s);
            ansL = l;
            ansR = r;
        }
        s >= 0 ? r-- : l++;
    }

    cout << arr[ansL] << ' ' << arr[ansR] << '\n';

    return 0;
}