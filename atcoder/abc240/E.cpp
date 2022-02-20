#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 201010;

int n;
vector<int> edges[N];
pii ans[N];
int cnt = 1;

void dfs(int node, int p) {
    ans[node].first = cnt;

    int first = true;
    for (auto &c : edges[node]) {
        if (c == p) continue;
        if (first) {
            first = false;
        } else {
            cnt++;
        }
        dfs(c, node);
    }
    ans[node].second = cnt;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 0, n-1) {
        int u, v; cin >> u >> v;
        u--, v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    dfs(0, -1);

    FOR(i, 0, n) {
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    }


    return 0;
}