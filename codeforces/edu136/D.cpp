#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 7)
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep_(i, a, b) for (int i = (a); i <= (b); ++i)
#define repr_(i, a, b) for (int i = (a); i >= (b); --i)
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

constexpr int N = 201010;
constexpr int M = 100;

ll n, m, k, q, ans;
int par[N], depth[N];
vector<vector<int>> child;

void dfs1(int node) {
    for (auto &c : child[node]) {
        depth[c] = depth[node] + 1;
        dfs1(c);
    }
}

pair<int, int> dfs2(int node, int x) {
    int res = 0;

    int rr = -1;
    for (auto &c : child[node]) {
        auto p = dfs2(c, x);
        res += p.first;
        rr = max(rr, p.second);
    }

    if (depth[node] > x) {
        rr = max(rr, max(2, depth[node] - x + 1)); 
    }

    if (rr == depth[node]) {
        rr = -1;
        res++;
    }

    return { res, rr };
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
        cin >> n >> k;

        child.clear();
        child = vector<vector<int>>(n, vector<int>());

        rep(i, 1, n) {
            ll x; cin >> x;
            x--;
            par[i] = x;
            child[x].push_back(i);
        }

        dfs1(0);

        int mx = n + 1;
        int x = 0;

        for (ll step = mx; step >= 1; step /= 2) {
            while (x + step < mx && dfs2(0, x + step).first > k)
                x += step;
        }

        ans = x + 1;
        
        cout << ans << '\n';
    }

    return 0;
}