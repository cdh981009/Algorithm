#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int(i) = (a); (i) < (b); ++(i))
#define FOR_(i, a, b) for (int(i) = (a); (i) <= (b); ++(i))

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

constexpr int N = 101010;
constexpr int M = 101010;

int n;
string color;
vector<int> edges[N];
ll cnt[N];
ll pp[N];
ll p[N];
ll ans;

void dfs1(int node, int par, int ppar) {
    p[node] = par;

    if (color[node] != 'B') {
        if (ppar == -1)
            ppar = node;
        cnt[node] = 1;
    }

    if (color[node] == 'B') {
        pp[node] = ppar;
        ppar = -1;
    }

    FOR(i, 0, edges[node].size()) {
        int c = edges[node][i];
        if (c == par) {
            continue;
        }
        dfs1(c, node, ppar);
        if (color[node] != 'B')
            cnt[node] += cnt[c];
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    cin >> color;

    dfs1(0, -1, -1);
    FOR(i, 0, n) {
        if (color[i] == 'B') {
            FOR(j, 0, edges[i].size()) {
                int c = edges[i][j];
                if (p[i] == c)
                    continue;
                ans += cnt[c];
            }
            if (pp[i] != -1) {
                ans += cnt[pp[i]];
            }
        }
    }

    cout << ans << '\n';

    return 0;
}