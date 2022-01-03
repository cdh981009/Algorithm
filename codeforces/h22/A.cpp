#include <bits/stdc++.h>

using namespace std;

#define INF 6e4
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 5e4 + 20;

using ll = long long;

int n, k;

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
        cin >> n >> k;
        if (n - n/2 >= k) {
            FOR(i, 0, n) {
                FOR(j, 0, n) {
                    if (i == j && i % 2 == 0 && k > 0) {
                        k--;
                        cout << 'R';
                    } else
                        cout << '.';
                }
                cout << '\n';
            }
        } else {
            cout << -1 << '\n';
        }
    }

    return 0;
}
