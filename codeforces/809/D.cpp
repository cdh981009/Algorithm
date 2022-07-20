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

constexpr int N = 101010;
constexpr int M = 100;

int n, k, ans;
int arr[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> k;
        int mx = 0;
        rep(i, 0, n) {
            cin >> arr[i];
            mx = max(arr[i], mx);
        }

        vector<int> vec(mx + 10, 0);
        rep(i, 0, n) {
            // iterate distinct florr(a/p) values in descending order
            int px = INF;
            for (int p = 1; p <= min(k, arr[i]);) {
                int x = arr[i] / p;

                vec[x + 1] = max(vec[x + 1], px);


                p = arr[i] / x + 1;
                px = x;
            }
            vec[0] = max(vec[0], px);
        }

        ans = INF;
        rep(i, 0, mx + 10) {
            vec[i] = max(i-1 >= 0 ? vec[i-1] : 0, vec[i]);
            ans = min(ans, vec[i] - i);
        }

        cout << ans << '\n';
    }

    return 0;
}