#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    while (tc--) {
        int n, m; cin >> n >> m;
        FOR(i, 0, n) {
            FOR(j, 0, m) {
                if (i == 0 && j == 0)
                    cout << "W";
                else
                    cout << "B";
            }
            cout << "\n";
        }
    }
    return 0;
}