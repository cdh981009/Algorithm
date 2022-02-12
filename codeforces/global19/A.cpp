#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 101010;

int n, s;
int ans;

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
        bool pos = false;
        int prev;
        FOR(i, 0, n) {
            int x;
            cin >> x;
            if (i > 0 && x < prev) {
                pos |= true;
            }
            prev = x;

        }

        cout << (pos ? "Yes" : "No") << '\n';

    }
    return 0;
}