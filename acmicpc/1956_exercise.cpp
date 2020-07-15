#include <bits/stdc++.h>

using namespace std;

#define INF 1e8
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int V = 400;
int n, m;
int adj[V+1][2 * V + 1];

void floyd() {
    FOR_(k, 1, n)
        FOR_(i, 1, n)
            FOR_(j, 1, 2*n)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    FOR_(i, 1, n)
        FOR_(j, 1, 2*n)
            adj[i][j] = (i == j ? 0 : INF);
    
    FOR(i, 0, m) {
        int a, b, c; cin >> a >> b >> c;
        adj[a][b] = adj[a][n+b] = min(adj[a][b], c);
    }

    floyd();
    int minDist = INF;
    FOR_(i, 1, n) {
        minDist = min(minDist, adj[i][n+i]);
    }
    
    cout << (minDist >= INF ? -1 : minDist) << "\n";
    return 0;
}