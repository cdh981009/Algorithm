#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin >> n;
        vector<int> arr;
        int state = 0;
        FOR(i, 0, n) {
            int x; cin >> x;
            if (arr.empty()) {
                arr.push_back(x);
            } else {
                int newState = x - arr.back();
                if ((state > 0 && newState > 0) || 
                        (state < 0 && newState < 0)) {
                    arr.pop_back();
                }
                state = newState;
                arr.push_back(x);
            }
        }
        cout << arr.size() << "\n";
        for (auto x : arr)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}