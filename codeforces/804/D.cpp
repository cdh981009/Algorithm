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

constexpr int N = 5010;
constexpr int M = 100;

ll n, m, k, q, ans;
ll arr[N];
bool isErasable[N][N];
ll dp[N];

ll getDp(int i) {
    auto& ref = dp[i];
    if (ref != -1) return ref;

    if (i == 0) {
        ref = 1;
    } else {
        if (isErasable[0][i - 1]) {
            ref = 1;
        } else {
            ref = 0;
        }

        rep(j, 0, i) {
            if (arr[j] != arr[i]) continue;
            if (j + 1 <= i - 1) {
                if (isErasable[j + 1][i - 1]) {
                    ref = max(ref, 1 + (getDp(j) == 0 ? -100 : getDp(j)));
                }
            } else {
                ref = max(ref, 1 + (getDp(j) == 0 ? -100 : getDp(j)));
            }
        }
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
        ans = 0;
        cin >> n;
        rep(i, 0, n) cin >> arr[i];
        memset(dp, -1, sizeof(ll) * n);

        rep(l, 0, n) {
            vector<int> freq(n + 1, 0);
            int mx = -1;

            rep(r, l, n) {
                if (++freq[arr[r]] > mx) {
                    mx = freq[arr[r]];
                }

                auto& ref = isErasable[l][r];
                if ((r - l + 1) % 2 == 1) {
                    ref = false;
                } else {
                    ref = (mx <= (r - l + 1) / 2);
                }
            }
        }

        ans = 0;
        rep(i, 0, n) {
            if (i == n - 1 || isErasable[i + 1][n - 1])
                ans = max(ans, getDp(i));
        }

        cout << ans << '\n';
    }

    return 0;
}