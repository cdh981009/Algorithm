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
        int n; cin >> n;
        vector<int> arr;
        FOR(i, 0, n) {
            int x; cin >> x;
            arr.push_back(x);
        }
        sort(arr.begin(), arr.end());
        for (int i = 0; i < (n+1)/2; ++i) {
            cout << arr[n - n/2 - 1 - i] << " ";
            if (n - n/2 - 1 - i != n/2 + i)
                cout << arr[n/2 + i] << " ";
        }
        cout << "\n";
    }
    return 0;
}