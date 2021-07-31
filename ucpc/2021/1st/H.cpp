#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 101010;

using ll = long long;
using pii = pair<int, int>;

ll ans;
int n, m, k, s, t;

vector<pii> edges[N];
vector<int> par[N];
ll dp[N][11];
bool memoi[N][11];

ll getDp(int node, int lift) {
    if (lift < 0)
        return -1;
    if (lift == 0 && node == t)
        return 0;
    
    ll& ref = dp[node][lift];
    bool& mem = memoi[node][lift];

    if (mem)
        return ref;
    mem = true;
    
    ll x;

    FOR(i, 0, par[node].size()) {
        int p = par[node][i];
        if ((x = getDp(p, lift - 1)) != -1)
            ref = max(ref, x);
    }
    
    FOR(i, 0, edges[node].size()) {
        int child = edges[node][i].first;
        int w = edges[node][i].second;
        if ((x = getDp(child, lift)) != -1)
            ref = max(ref, x + w);
    }

    return ref;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m >> k >> s >> t;

    FOR(i, 0, m) {
        int a, b, t;
        cin >> a >> b >> t;
        edges[a].push_back({b, t});
        par[b].push_back(a);
    }

    memset(dp, -1, sizeof(ll) * N * 11);

    ans = getDp(s, k);

    cout << ans << '\n';

    return 0;
}