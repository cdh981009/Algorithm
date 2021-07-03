#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int n, a, b;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n >> a >> b;
        bool ans = false;
        if (n == 1) {
            ans = true;
        } else if (a == 1) {
            ans = ((n - 1) % b == 0);
        } else {
            long long x = 1;
            while (x <= n) {
                if ((n - x) % b == 0) {
                    ans = true;
                    break;
                }
                x *= a;
            }
        }
        cout << (ans ? "Yes" : "No") << '\n';
    }
    return 0;
}