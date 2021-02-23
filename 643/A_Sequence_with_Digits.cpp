#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    while (tc--) {
        long long a, k; cin >> a >> k;
        while (k--) {
            int minD = 9;
            int maxD = 0;
            long long n = a;
            while (n > 0) {
                int digit = n % 10;
                minD = min(minD, digit);
                if (minD == 0) break;
                maxD = max(maxD, digit);
                n /= 10;
            }
            if (minD == 0) break;
            if (k > 0)
                a += minD * maxD;
        }
        cout << a << "\n";
    }
    return 0;
}