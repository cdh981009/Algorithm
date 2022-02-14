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

        int po, pe;
        po = pe = 0;
        FOR(i, 0, n) {
            int x = a[i];
            if (x % 2) {
                if (x < po) {
                    pos = false;
                    break;
                }
                po = x;
            } else {
                if (x < pe) {
                    pos = false;
                    break;
                }
                pe = x;
            }
        }

        cout << (pos ? "Yes" : "No") << '\n';
    }
    return 0;
}