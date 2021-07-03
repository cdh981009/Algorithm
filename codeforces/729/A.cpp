#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)


int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        int n; cin >> n;
        int cnt = 0;
        FOR(i, 0, 2 * n) {
            int x; cin >> x;
            if (x % 2 == 0)
                cnt++;
        }
        if (cnt == n) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}