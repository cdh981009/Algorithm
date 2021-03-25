// 2188: 축사 배정
// https://www.acmicpc.net/problem/2188
#include <bits/stdc++.h>

using namespace std;

#define INF 1e6
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 200;

// bipartite maximum matching
// use dfs

int n, m;
bool adj[N][N];
bool visited[N];
int aMatch[N], bMatch[N];

bool dfs(int a) {
    if (visited[a])
        return false;
    visited[a] = true;

    FOR(b, 0, m) {
        if (adj[a][b]) {
            if (bMatch[b] == -1 || dfs(bMatch[b])) {
                bMatch[b] = a;
                aMatch[a] = b;
                return true;
            }
        }
    }

    return false;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    FOR(i, 0, n) {
        int x; cin >> x;
        FOR(j, 0, x) {
            int y; cin >> y;
            adj[i][y - 1] = true;
        }
    }

    memset(bMatch, -1, sizeof(int) * N);
    
    int ans = 0;
    FOR(s, 0, n) {
        memset(visited, false, sizeof(bool) * N);

        if (dfs(s))
            ans++;
    }

    cout << ans << '\n';

    return 0;
}