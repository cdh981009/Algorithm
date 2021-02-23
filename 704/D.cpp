#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 2e5 + 10;
int a, b, k, n;
int x[N], y[N], z[N];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> a >> b >> k;
    n = a + b;
    x[0] = y[0] = 1;
    bool p = (k <= n - 2 && (a >= 1 || (a == 0 && k == 0)));
    if (b == 1 && k != 0)
        p = false;
    cout << (p ? "Yes" : "No") << '\n';

    if (p) {
        for (int i = n - 1, cnt = 0; cnt < b - 1; ++cnt, --i) {
            y[i] = 1;
        }
        if (k < b - 1) {
            for (int i = n - (b - 1), cnt = 0; cnt < k; ++cnt, ++i) {
                z[i] = 1;
            }
        } else {
            for (int i = n - 1, cnt = 0; cnt < k; ++cnt, --i) {
                z[i] = 1;
            }
        }
        for (int i = n - 1; i >= 1; --i) {
            x[i] += y[i] + z[i];
            x[i - 1] += x[i] / 2;
            x[i] %= 2;
        }
        FOR(i, 0, n) {
            cout << x[i];
        }
        cout << '\n';
        FOR(i, 0, n) {
            cout << y[i];
        }
        cout << '\n';
    }

    return 0;
}