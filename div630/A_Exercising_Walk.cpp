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
        int a, b, c, d; cin >> a >> b >> c >> d;
        int x, y, x1, y1, x2, y2; cin >> x >> y >> x1 >> y1 >> x2 >> y2;
        bool possible = true;
        int xRes = b-a+x;
        int yRes = d-c+y;
        if (x2 == x1 && a + b != 0) {
            possible = false;
        } else if (y2 == y1 && c + d != 0) {
            possible = false;
        } else if (xRes < x1 || xRes > x2 || yRes < y1 || yRes > y2) {
            possible = false;
        }
        cout << (possible ? "Yes" : "No") << "\n";
    }
    return 0;
}