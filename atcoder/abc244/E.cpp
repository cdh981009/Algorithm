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
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 2010;
constexpr int M = 998244353;

int n, m, k, s, t, x;
vi edge[N];

ll dp[N][N][2];

ll getDp(int ind, int curr, int par) {
    if (ind == k) return (curr == t && par == 0);

    if (curr == x) par ^= 1;

    ll& ref = dp[ind][curr][par];
    if (ref != -1) return ref;
    ref = 0;

    for (auto& nxt : edge[curr]) {
        ref += getDp(ind + 1, nxt, par);
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

    cin >> n >> m >> k >> s >> t >> x;

    ll ans = 0;

    s--;
    t--;
    x--;

    FOR(i, 0, m) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    memset(dp, -1, sizeof(dp));

    ans = getDp(0, s, 0);

    cout << ans << '\n';

    return 0;
}