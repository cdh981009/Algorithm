#include <bits/stdc++.h>

using namespace std;

#define INF (1e9+7)
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
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pii>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 101010;
constexpr int M = 100;

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
        ll n, ans;
        cin >> n;
        vl arr(n);
        FOR(i, 0, n) cin >> arr[i];
        ans = 0;

        vl sm(n);
        for (int i = n -1; i >= 0; --i) {
            if (i == n -1) {
                sm[i] = arr[i];
            } else {
                sm[i] = min(arr[i], sm[i + 1]);
            }
        }

        ll sdc = 0;
        ll mn = arr[0];
        FOR(i, 0, n-1) {
            ll x = abs(arr[i] - arr[i + 1]);
            ans += x;
            if (arr[i] - arr[i + 1] > 0) {
                mn -= x;
            } else {
                sdc += x;
            }

            mn = min(mn, arr[i+1] - sdc);
        }

        ans += abs(mn);

        cout << ans << '\n';
    }

    return 0;
}