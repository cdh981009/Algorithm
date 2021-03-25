// 16163: #15164번_제보
// https://www.acmicpc.net/problem/16163
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 4e6;
char arr[N];
int a[N];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    char c;
    int n = 0;
    while (cin >> c) {
        arr[2 * n] = c;
        arr[2 * n + 1] = '#';
        n++;
    }

    long long sum = 0;
    // Manacher
    int R = 0;
    int p = 0;
    FOR(i, 0, 2 * n - 1) {
        int j = 2 * p - i;

        if (i <= R) {
            a[i] = min(R - i, a[j]);
        } // else a[i] = 0;

        int k = a[i] + 1;
        while ((i - k >= 0) && (i + k < 2 * n - 1) && (arr[i - k] == arr [i + k])) {
            ++k;
            ++a[i];
        }

        if (i + a[i] > R) {
            R = i + a[i];
            p = i;
        }

        if (arr[i] == '#') {
            sum += (a[i] + 1) / 2;
        } else {
            sum += a[i] / 2 + 1;
        }
    }

    cout << sum << '\n';

    return 0;
}