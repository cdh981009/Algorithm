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

    int n; cin >> n;
    vector<int> arr(n);
    vector<int> uniqueArr;
    bool possible = true;
    FOR(i, 0, n) {
        int x; cin >> x;
        arr[i] = x;
        if (uniqueArr.empty() || uniqueArr.back() != x)
            uniqueArr.push_back(x);
        if (x - 1 > i) {
            possible = false;
        }
    }
    if (!possible) {
        cout << -1 << "\n";
    } else {
        int notAppear = 0;
        int uInd = 0;
        vector<int> ans(n);
        FOR(i, 0, n) {
            if (i == 0 || arr[i] == arr[i-1]) {
                while (true) {
                    if (notAppear == uniqueArr[uInd]) {
                        notAppear++;
                        uInd++;
                    } else {
                        break;
                    }
                }
                ans[i] = notAppear++;
            } else {
                ans[i] = arr[i-1];
            }
        }
        for (auto v : ans) {
            cout << v << " ";
        }
        cout << "\n";
    }

    return 0;
}