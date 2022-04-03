#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 10)
#define fi first
#define se second
#define rep(i, a, b) for (ll i = (a); i < (b); ++i)
#define rep_(i, a, b) for (ll i = (a); i <= (b); ++i)
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (ll i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pii>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 2001;
constexpr int M = 100;

ll n, k, m, ans;
vector<vi> edges;
vl fun, p;

ll dfs(int node) {
    ll base = fun[node];
    ll mn = INF;
    ll sum = 0;

    for (auto &c : edges[node]) {
        ll ret = dfs(c);
        if (ret < mn) {
            mn = ret;
        }
        sum += ret;
    }

    if (mn == INF) mn = 0;
    sum -= mn;
    ans += sum;

    return max(base, mn);
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    rep_(testcase, 1, tc) {
        cout << "Case #" << testcase << ": ";
        cin >> n;

        fun = vl(n + 1, 0);
        p = vl(n + 1, 0);
        edges = vector<vi>(n + 1);

        rep_(i, 1, n) cin >> fun[i];
        rep_(i, 1, n) {
            int x;
            cin >> x;
            edges[x].push_back(i);
            p[i] = x;
        }

        ans = 0;
        rep_(i, 1, n) {
            if (p[i] == 0)
                ans += dfs(i);
        }

        cout << ans << '\n';
    }

    return 0;
}