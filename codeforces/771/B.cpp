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
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        int n, ans;
        cin >> n;
        vector<int> a(n);
        FOR(i, 0, n) cin >> a[i];
        bool pos = true;

        while (true) {
            bool c = false;
            FOR(i, 0, n - 1) {
                if (a[i] > a[i + 1] && ((a[i] + a[i + 1]) % 2 == 1)) {
                    swap(a[i], a[i + 1]);
                    c = true;
                }
            }
            if (!c) {
                FOR(i, 0, n - 1) {
                    if (a[i] > a[i + 1]) {
                        pos = false;
                    }
                }
                break;
            }
        }

        cout << (pos ? "Yes" : "No") << '\n';
    }
    return 0;
}