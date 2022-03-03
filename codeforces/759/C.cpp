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
        int n, k; cin >> n >> k;
        vl a, b;
        FOR(i, 0, n) {
            int x; cin >> x;
            if (x > 0)
                a.push_back(x);
            else 
                b.push_back(-x);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        ll ans = 0;
        ll mx = -1;
        for (int i = a.size() - 1; i >= 0; i -= k) {
            if (mx < a[i]) {
                mx = a[i];
            }
            ans += 2 * a[i];
        }

        for (int i = b.size() - 1; i >= 0; i -= k) {
            if (mx < b[i]) {
                mx = b[i];
            }
            ans += 2 * b[i];
        }

        ans -= mx;
        cout << ans << '\n';
    }

    return 0;
}