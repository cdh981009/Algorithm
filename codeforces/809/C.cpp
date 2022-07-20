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

ll n, m, k, q, ans;
ll arr[N];
ll dp[N][2][2];

ll getDp(int ind, bool prev, bool d) {
    ll &ref = dp[ind][prev][d];
    if (ref != -1) return ref;

    if (ind == 0) return ref = getDp(ind + 1, false, false);
    if (ind == n - 1) return 0;

    if (prev == false) {  // 전에 안고름
        // 나는 골라야함
        ref = max(0LL, 1 + max(arr[ind - 1], arr[ind + 1]) - arr[ind]) +
              getDp(ind + 1, true, d);

        if (d == false) {  //  d가 false면 안골라도 됨
            ref = min(ref, getDp(ind + 1, false, true));
        }
    } else {  // 전에 고름
        // 나는 고르지 말아야함
        ref = getDp(ind + 1, false, d);
    }
    return ref;
}

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
        cin >> n;
        ans = 0;
        rep(i, 0, n) cin >> arr[i];
        rep(i, 0, n) {
            rep(j, 0, 2) rep(k, 0, 2) dp[i][j][k] = -1;
        }

        if (n % 2) {
            rep(i, 0, n) {
                if (i % 2) {
                    ans += max(0LL, 1 + max(arr[i - 1], arr[i + 1]) - arr[i]);
                }
            }
        } else {
            ans = getDp(0, 0, false);
        }

        cout << ans << '\n';
    }

    return 0;
}