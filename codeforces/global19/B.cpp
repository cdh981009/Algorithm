#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 101;

int n;
vector<int> v;

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
        v = vector<int>(n + 1);
        FOR(i, 0, n) {
            int x; cin >> x;
            v[i + 1] = v[i] + (x == 0);
        }
        ll ans = 0;
        
        FOR_(i, 1, n) {
            FOR_(j, i, n) {
                ans += v[j] - v[i - 1] + j - i + 1;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}