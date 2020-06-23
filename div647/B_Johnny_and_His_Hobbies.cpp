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
        int n; cin >> n;
        vector<int> arr(n);
        vector<bool> appear(1025, false);
        FOR(i, 0, n) {
            int x; cin >> x;
            appear[x] = true;
            arr[i] = x;
        }
        int ans = -1;
        FOR_(i, 1, 1024) {
            vector<bool> trans(1025, false);
            for (auto x : arr) {
                int y = x ^ i;
                if (y <= 1024)
                    trans[y] = true;
            }
            if (appear == trans) {
                ans = i;
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}