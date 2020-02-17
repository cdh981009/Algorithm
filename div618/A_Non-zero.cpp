#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR (i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define FOR_ (i, a, b) for (int (i) = (a); (i) <= (b); ++(i))

int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    while (tc--) {
        int len; cin >> len;
        int sum = 0;
        int cntZero = 0;
        int ans = 0;
        while (len--) {
            int n; cin >> n;
            sum += n + (n == 0 ? 1 : 0);
            cntZero += (n == 0 ? 1 : 0);
        }
        ans = cntZero + (sum == 0 ? 1 : 0);
        cout << ans << "\n";
    }
    return 0;
}