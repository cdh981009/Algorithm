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
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 9010;
constexpr int M = 100;

ll n, m, k, q, ans;
ll a[N];
ll dp[N], aux[N];

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
        memset(dp, 0, sizeof(dp));
        memset(aux, 0, sizeof(aux));

        rep(i, 0, n) cin >> a[i];

        for (int i = n - 1; i >= 0; --i) {
            rep(j, 0, N) {
                auto &ref = dp[j];
                if (j == 0)
                    ref = aux[a[i + 1]];
                else {
                    ref = 1 + aux[a[i + 1]];
                    if (i + 1 < n)
                        ref = min(ref, 1 + aux[a[i + 1] ^ j]);
                }
            }
            swap(dp, aux);
        }


        cout << aux[a[0]] << '\n';
    }

    return 0;
}