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

constexpr int N = 1000;
constexpr int M = 100;

int n, m;
vpii edges[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    rep(i, 0, m) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges[u].push_back({v, w});
    }

    int s, e;
    cin >> s >> e;
    s--, e--;

    priority_queue<pii> q;
    vector<int> dist(n, INF);
    dist[s] = 0;
    q.push({0, s});

    while (!q.empty()) {
        auto [d, curr] = q.top();
        q.pop();
        d = -d;

        if (curr == e) {
            cout << d << '\n';
            break;
        }

        if (d > dist[curr]) continue;

        for (auto &[nxt, w] : edges[curr]) {
            if (d + w < dist[nxt]) {
                dist[nxt] = d + w;
                q.push({-dist[nxt], nxt});
            }
        }
    }


    return 0;
}