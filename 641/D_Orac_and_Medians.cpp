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
        int n, k; cin >> n >> k;
        vector<bool> arr(n);
        bool exist = false;
        FOR(i, 0, n) {
            int x; cin >> x;
            arr[i] = (x >= k ? 1 : 0);
            if (x == k)
                exist = true;
        }
        bool possible = false;
        if (n == 1 && exist) possible = true;

        FOR(i, 0, n) {
            if (i >= 1 && arr[i - 1] && arr[i])
                possible = true;
            if (i >= 2 && arr[i - 2] && arr[i])
                possible = true;
        }

        if (!exist) possible = false;
        cout << (possible ? "yes" : "no") << "\n";
    }
    return 0;
}