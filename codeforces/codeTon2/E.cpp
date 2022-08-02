#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 10)
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep_(i, a, b) for (int i = (a); i <= (b); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pii>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 1010;
constexpr int M = 998244353;

ll n, m, ans;
ll a[N], b[N];
vector<vector<int>> adj, back;
ll dp[N];

ll getDp(int x) {
    auto& ref = dp[x];
    if (ref != -1) return ref;
    ref = a[x] % M;

    for (auto prev : back[x]) {
        ref = ref + getDp(prev);
        ref %= M;
    }

    return ref;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        rep(i, 0, n) cin >> a[i];
        adj = vector<vector<int>>(n);
        back = vector<vector<int>>(n);
        rep(i, 0, m) {
            ll x, y;
            cin >> x >> y;
            x--, y--;
            adj[x].push_back(y);
            back[y].push_back(x);
        }

        ll ans = -1;

        rep(i, 0, n) {
            bool e = true;
            rep(j, 0, n) {
                if (a[j] != 0) {
                    e = false;
                    break;
                }
            }

            if (e) {
                ans = i;
                break;
            }

            vector<int> vec;
            rep(j, 0, n) {
                if (a[j] == 0) continue;
                vec.push_back(j);
            }
            for (auto curr: vec) {
                a[curr]--;
                for (auto next : adj[curr]) {
                    a[next]++;
                }
            }
        }

        if (ans == -1) {
            memset(dp, -1, sizeof(dp));
            rep(i, 0, n) {
                if (adj[i].size() == 0) {
                    ans = getDp(i);
                    break;
                }
            }
            ans += n;
            ans %= M;
        }

        cout << ans << '\n';
    }

    return 0;
}