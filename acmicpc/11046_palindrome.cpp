// 11046: 팰린드롬??
// https://www.acmicpc.net/problem/11046
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 2e6 + 10;
int arr[N];
int a[N];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    FOR(i, 0, n) {
        int x;
        cin >> x;
        arr[i * 2] = x;
        arr[i * 2 + 1] = 0;
    }

    int R = 0;
    int p = 0;
    FOR(i, 1, 2 * n - 1) {
        int j = 2 * p - i;

        if (i <= R) {
            a[i] = min(R - i, a[j]);
        } // else a[i] = 0;

        int k = a[i] + 1;
        while ((i - k >= 0) && (i + k < 2 * n - 1) && (arr[i - k] == arr[i + k])) {
            a[i]++;
            k++;
        }

        if (a[i] + i > R) {
            R = a[i] + i;
            p = i;
        }
    }

    int q = 0;
    cin >> q;
    FOR(i, 0, q) {
        int s, e;
        cin >> s >> e;
        s--;
        e--;
        // sReal = 2 * s;
        // eReal = 2 * e;
        int m = s + e;
        int r = e - s;

        cout << (a[m] >= r) << '\n';
    }

    return 0;
}