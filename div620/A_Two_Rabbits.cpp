#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define FOR_(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))

int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    while (tc--) {
        int x, y, a, b; cin >> x >> y >> a >> b;
        int sum = a + b;
        int delta = y - x;
        if (delta % sum == 0)
            cout << delta / sum << "\n";
        else
            cout << "-1\n";
    }
    return 0;
}