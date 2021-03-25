// 1671: 상어의 저녁식사
// https://www.acmicpc.net/problem/1671
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int M = 50;

int n;
int shark[M][3];
bool adj[M][M];
bool visited[2 * M];
int match[M];

bool dfs(int a) {
    if (visited[a])
        return false;
    visited[a] = true;

    FOR(b, 0, n) {
        if (adj[a / 2][b] && (match[b] == -1 || dfs(match[b]))) {
            match[b] = a;
            return true;
        }
    }
    return false;
}

int bipartite() {
    memset(match, -1, sizeof(int) * M);
    int m = 0;
    FOR(i, 0, 2 * n) {
        memset(visited, 0, sizeof(bool) * (2 * M));
        m += dfs(i);
    }
    return m;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 0, n) {
        FOR(j, 0, 3) {
            int x;
            cin >> x;
            shark[i][j] = x;
        }
    }

    FOR(i, 0, n) {
        FOR(j, 0, n) {
            int equal = 0;
            int greater = 0;
            FOR(k, 0, 3) {
                equal += (shark[i][k] == shark[j][k]);
                greater += (shark[i][k] > shark[j][k]);
            }
            if (equal == 3 && i > j) {
                adj[i][j] = true;
            } else if (equal != 3 && equal + greater == 3) {
                adj[i][j] = true;
            }
        }
    }

    cout << n - bipartite() << endl;
    return 0;
}