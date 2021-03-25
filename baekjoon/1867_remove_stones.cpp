// 1867: 돌멩이 제거
// https://www.acmicpc.net/problem/1867
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int M = 500;

int n, k;
vector<int> adj[M];
bool visited[M];
int match[M];

bool dfs(int a) {
    if (visited[a])
        return false;
    visited[a] = true;

    for (const auto& b : adj[a]) {
        if (match[b] == -1 || dfs(match[b])) {
            match[b] = a;
            return true;
        }
    }
    return false;
}

int bipartite() {
    memset(match, -1, sizeof(int) * M);
    int m = 0;
    FOR(i, 0, n) {
        memset(visited, 0, sizeof(bool) * M);
        m += dfs(i);
    }
    return m;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    FOR(i, 0, k) {
        int x, y; cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
    }

    cout << bipartite() << endl;
    return 0;
}