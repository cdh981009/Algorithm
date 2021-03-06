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
        vector<int> a;
        vector<int> b;
        FOR(i, 0, 2*n) {
            int x; cin >> x;
            if (i < n)
                a.push_back(x);
            else
                b.push_back(x);
        }
        bool one = false;
        bool negOne = false;
        bool possible = true;
        FOR(i, 0, n) {
            if (a[i] > b[i])
                possible = possible & negOne;
            else if (a[i] < b[i])
                possible = possible & one;
            one = one | (a[i] == 1);
            negOne = negOne | (a[i] == -1);
        }
        cout << (possible ? "YES" : "NO") << "\n";
    }
    return 0;
}