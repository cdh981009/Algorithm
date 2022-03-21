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


constexpr int N = 17;
constexpr int M = 100;

int n, m;
vi edges[N];
bool adj[N][N];

int dist[1<<N][N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    FOR(i, 0, m) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
        adj[u][v] = true;
        adj[v][u] = true;
    }

    FOR(i, 0, 1<<n) {
        FOR(j, 0, n) {
            if (i == 0) dist[i][j] = 0;
            else if ((i ^ (1 << j)) == 0) dist[i][j] = 1;
            else dist[i][j] = INF;
        }
    }

    queue<pii> q;
    FOR(i, 0, n) {
        q.push({1 << i, i});
    }

    while (!q.empty()) {
        auto [state, curr] = q.front();
        q.pop();

        FOR(i, 0, n) {
            if (adj[curr][i]) {
                int ns = (state ^ (1 << i));
                if (dist[ns][i] == INF) {
                    dist[ns][i] = dist[state][curr] + 1;
                    q.push({ns, i});
                }
            }
        }
    }

    ll ans = 0;

    FOR(i, 0, 1<<n) {
        int res = INF;
        FOR(j, 0, n) {
            res = min(res, dist[i][j]);
        }
        ans += res;
    }

    cout << ans << '\n';

    return 0;
}