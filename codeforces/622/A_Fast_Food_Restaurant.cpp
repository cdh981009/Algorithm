#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define FOR_(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int tc; cin >> tc;
    while (tc--) {
        vector<int> perm = {1, 2, 3, 4, 5, 6, 7};
        int a, b, c; cin >> a >> b >> c;
        int ans = 0;
        do {
            int f[3] = {a, b, c};
            int setCnt = 0;
            FOR(i, 0, 7) {
                bool possible = true;
                FOR(j, 0, 3)
                    possible = (perm[i] & (1 << j) && f[j] <= 0) ? false : possible;
                if (possible) {
                    FOR(j, 0, 3)
                        f[j] -= (perm[i] & (1 << j)) ? 1 : 0;
                    setCnt++;
                }
            }
            ans = max(ans, setCnt);
        } while (next_permutation(perm.begin(), perm.end())); 
        cout << ans << "\n";
    }

    return 0;
}