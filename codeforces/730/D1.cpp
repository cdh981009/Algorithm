#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        int n, k;
        cin >> n >> k;

        int xSum = 0;
        int i = 0;

        while (true) {
            int y = xSum ^ i;
            xSum ^= y;
            i++;
            cout << y << '\n';
            cout.flush();
            int x;
            cin >> x;
            if (x == 1) {
                break;
            } else if (x == 0) {
                continue;
            } else {
                return 0;
            }
        }
    }
    return 0;
}