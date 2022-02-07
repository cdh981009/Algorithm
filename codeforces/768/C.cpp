#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 100;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        int n, k;
        cin >> n >> k;
        bool pos = true;

        if (n == 4 && k == 3) pos = false;

        if (!pos) cout << -1 << '\n';
        else {
            if (k == n - 1) {
                FOR(i, 0, n/2) {
                    int a, b;
                    if (i == 0) {
                        a = n - 1;
                        b = n - 2;
                    } else if (i == 1) {
                        a = 0;
                        b = 2;
                    } else if (i == 2) {
                        a = 1;
                        b = n - 3;
                    } else {
                        a = i;
                        b = i ^ (n - 1);
                    }
                    cout << a << ' ' << b << '\n';
                }
            } else {
                FOR(i, 0, n/2) {
                    int a, b;
                    if (i == 0) {
                        a = n - 1;
                        b = k;
                    } else {
                        a = i;
                        b = i ^ (n - 1);
                        if (a == k) {
                            a = 0;
                        }
                        if (b == k) {
                            b = 0;
                        }
                    }
                    cout << a << ' ' << b << '\n';
                }
            }
        }
    }
    return 0;
}