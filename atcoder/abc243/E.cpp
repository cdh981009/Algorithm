#include <bits/stdc++.h>

using namespace std;

#define INF 1e14
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

constexpr int N = 310;
constexpr int M = 100;

ll adj[N][N];

struct Edge {
    ll a, b, c;
    bool operator<(const Edge& o) {
        return c < o.c;
    }
};

vector<Edge> edges;

int n, m;

void floyd() {
    FOR(k, 0, n)
        FOR(i, 0, n)
            FOR(j, 0, n)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    FOR(i, 0, n) {
        FOR(j, 0, n) {
            adj[i][j] = INF;
            if (i == j) adj[i][j] = 0;
        }
    }

    FOR(i, 0, m) {
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        adj[a][b] = c;
        adj[b][a] = c;
        edges.push_back({a, b, c});
    }

    floyd();
    sort(edges.rbegin(), edges.rend());

    int cnt = 0;
    for (auto &[a, b, c] : edges) {
        if (adj[a][b] < c) {
            cnt++;
        }
        else if (adj[a][b] == c) {
            bool another = false;
            FOR(i, 0, n) {
                if (a == i || i == b) continue;
                if (adj[a][i] + adj[i][b] == c) {
                    another = true;
                    break;
                }
            }

            if (another) cnt++;
        }
    }

    cout << cnt << '\n';
    
    return 0;
}