// 9184: Function Run Fun
// https://www.acmicpc.net/problem/9184
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 21;
int dp[21][21][21];
bool memoi[21][21][21];

int w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }

    if (a > 20 || b > 20 || c > 20) {
        return w(20, 20, 20);
    }

    int& ref = dp[a][b][c];

    if (memoi[a][b][c]) {
        return ref;
    }

    if (a < b && b < c) {
        ref = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    } else {
        ref = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    }

    memoi[a][b][c] = true;
    return ref;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c;

    while (cin >> a >> b >> c) {
        if (a == -1 && b == -1 && c == -1)
            break;
        cout << "w("
             << a << ", "
             << b << ", "
             << c << ") = "
             << w(a, b, c) << '\n';
    }

    return 0;
}