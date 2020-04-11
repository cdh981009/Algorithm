#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define FOR_(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    FOR_(t, 1, tc) {
        int n; cin >> n;
        cout << "Case #" << t << ":\n";
        int side = min(n, 30);
        n -= side;
        int popCount = 0;
        bool leftToRight = true;
        FOR_(i, 1, side) {
            if (n & (1 << (i-1))) {
                popCount++;
                FOR_(j, 1, i) {
                    cout << (i) << " " << (leftToRight ? j : (i - j + 1)) << "\n";
                }
                leftToRight = !leftToRight;
            } else {
                cout << (i) << " " << (leftToRight ? 1 : i) << "\n";
            }
        }
        FOR_(i, 1, popCount) {
            cout << side + i << " " << (leftToRight ? 1 : side + i) << "\n";
        }
    }
    return 0;
}