// 1311: 할 일 정하기
// https://www.acmicpc.net/problem/1311
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

const int N = 100;
const int M = 5000;

// bipartite maximum matching

int n, m;

bool adj[N][N];

int aMat[N];
int bMat[N];
bool visited[N];

bool dfs(int a) {
    if (visited[a])
        return false;
    visited[a] = true;

    FOR(b, 0, N) {
        if (!adj[a][b])
            continue;
        if (bMat[b] == -1 || dfs(bMat[b])) {
            bMat[b] = a;
            aMat[a] = b;
            return true;
        }
    }
    return false;
}
int match() {
    memset(bMat, -1, sizeof(int) * N);
    int res = 0;
    FOR(i, 0, n) {
        memset(visited, 0, sizeof(bool) * N);
        res += dfs(i);
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    FOR(i, 0, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a][b] = true;
    }

    cout << match() << '\n';
    
    return 0;
}