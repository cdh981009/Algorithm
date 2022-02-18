#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 100;
constexpr int M = 100;

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
        int n, a, b;
        cin >> n;

        if (n % 2 == 0) {
            a = n/2;
            b = a - 1;
        } else {
            if (n % 4 == 1) {
                a = n/2 - 1;
                b = n/2 + 1;
            } else {
                a = n/2 - 2;
                b = n/2 + 2;
            }
        }

        cout << a << ' ' << b << ' ' << 1 << '\n';
    }
    return 0;
}