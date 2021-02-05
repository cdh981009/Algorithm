// 2467: 용액
// https://ww.acmicpc.net/problem/2467
#include <bits/stdc++.h>

using namespace std;

#define INF 2e9 + 1
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e5;

int arr[N];
int n;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 0, n) {
        cin >> arr[i];
    }

    int min = INF;
    int al, ar;
    int l, r;
    l = 0;
    r = n - 1;

    while (l < r) {
        int x = arr[l] + arr[r];
        if (abs(x) < min) {
            min = abs(x);
            al = l;
            ar = r;
        }

        if (x > 0) {
            r--;
        } else {
            l++;
        }
    }

    cout << arr[al] << " " << arr[ar] << "\n";

    return 0;
}