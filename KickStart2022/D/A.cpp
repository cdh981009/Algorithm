#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 7)
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep_(i, a, b) for (int i = (a); i <= (b); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)
#define printYN(pos) cout << (pos ? "YES" : "NO") << '\n'
#define printPOS(pos) cout << (pos ? "POSSIBLE" : "IMPOSSIBLE") << '\n'

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 1030;
constexpr int M = 100;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    for (int testcase = 1; testcase <= tc; ++testcase) {
        cout << "Case #" << testcase << ": ";

        ll n, m;
        cin >> n >> m;
        vector<ll> arr(n);
        rep(i, 0, n)
            cin >> arr[i];

        sort(arr.rbegin(), arr.rend());
        double ans = 0;
        rep(i, 0, m) {
            if (i != m-1) {
                ans += arr[i];
            } else {
                if ((n - m + 1) % 2 == 1) {
                    ans += arr[m-1 + (n-m+1)/2];
                } else {
                    ans += ((double)arr[m-1 + (n-m+1)/2] + arr[m-1 + (n-m+1)/2-1])/2.;
                }
            }
        }

        cout << fixed << setprecision(10) << ans << '\n';
    }


    return 0;
}