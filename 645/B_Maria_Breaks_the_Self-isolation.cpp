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
        vector<int> vec(n);
        FOR(i, 0, n) {
            int x; cin >> x;
            vec[i] = x;
        }
        sort(vec.begin(), vec.end());
        int ans = 1;
        for (int i = n - 1; i >= 0; --i) {
            if (i + 1 >= vec[i]) {
                ans = i + 2;
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}