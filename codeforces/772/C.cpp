#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 100;
constexpr int M = 100;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        int n, ans;
        cin >> n;
        vector<int> a(n);
        vector<tuple<int, int, int>> v;
        FOR(i, 0, n)
            cin >> a[i];
        if (a[n - 2] > a[n - 1]) {
            cout << -1 << '\n';
        } else {
            bool pos = true;
            if (a[n-2] >= 0 || a[n-1] >= 0) {
                int x = a[n-1];

                for (int i = n - 3; i >= 0; --i) {
                    a[i] = a[i+1] - x;
                    v.push_back({i, i+1, n-1});
                }
            } else { // edge case, check if array is already non decreasing
                for (int i = n - 3; i >= 0; --i) {
                    if (a[i] > a[i+1]) {
                        pos = false;
                        break;
                    }
                }
            }

            if (pos) {
                cout << v.size() << '\n';
                for (auto &[x, y, z] : v) {
                    cout << x+1 << ' ' << y+1 << ' ' << z+1 << '\n';
                }
                } else {
                    cout << -1 << '\n';
                }
        }
    }
    return 0;
}