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

ll n, m;
vector<pair<int, int>> edges[N];
vector<int> ans;

bool vst[N];

bool dfs(int node, int pre) {
    vst[node] = true;
    if (node != 1) ans.push_back(node);

    for (auto &[child, d] : edges[node]) {
        if (child == pre) continue;

        if (d < 0) return true;

        if (vst[child]) continue;
        if (dfs(child, node) == true) return true;
    }

    return false;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    bool all = false;
    ll n, m, t;
    cin >> n >> m;
    rep(i, 0, m) {
        ll u, v, a, b;
        cin >> u >> v >> a >> b;

        ll c = a + b;
        edges[u].push_back({v, c});
        edges[v].push_back({u, c});
    }
    cin >> t;
    t *= 2;

    vector<long long> dist(n + 1, 1e16);
    vector<bool> visited(n + 1, false);

    all = dfs(1, 0);

    if (!all) {
        ans.clear();

        priority_queue<pll, vector<pll>, greater<pll>> q;  // pair<distance, vertex>
        q.push({0, 1});

        while (!q.empty()) {
            auto top = q.top();
            q.pop();
            auto d = top.first;
            auto node = top.second;
            // cout << "node " << node << " dist " << d << endl;
            if (visited[node])
                continue;
            dist[node] = d;
            visited[node] = true;
            for (auto next : edges[node]) {
                auto dst = next.first;
                if (visited[dst])
                    continue;
                auto weight = next.second;
                q.push({d + weight, dst});
            }
        }

        rep_(i, 2, n) {
            if (dist[i] <= t)
                ans.push_back(i);
        }
    } else {
        ans.clear();
        rep_(i, 2, n) {
            ans.push_back(i);
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    if (ans.size() > 0) {
        for (auto x : ans) {
            cout << x << ' ';
        }
        cout << '\n';
    }

    return 0;
}