#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pii>;

constexpr int N = 101010;
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
        int n; cin >> n;
        vi a(n);
        FOR(i, 0, n) {
            cin >> a[i];
        }

        int ans = 0;
        int mx = -1;
        for (int i = n - 1; i >= 0; --i) {
            if (mx < a[i]) {
                ans++;
                mx = a[i];
            }
        }

        cout << ans - 1 << '\n';
    }

    return 0;
}