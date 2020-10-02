// 11375: 열혈강호
// https://www.acmicpc.net/problem/11375
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e3;
constexpr int M = 1e3;

int n, m;
vector<int> edge[N + 1];
bool visited[N + 1];
int aMatch[N + 1];
int bMatch[M + 1];

bool dfs(int a) {
    if (visited[a]) return false;
    visited[a] = true;
    for (auto b : edge[a]) {
        if (bMatch[b] == 0 || dfs(bMatch[b])) {
            aMatch[a] = b;
            bMatch[b] = a;
            return true;
        }
    }
    return false;
}

int bipartiteMatch() {
    int match = 0;
    FOR_(i, 1, n) {
        memset(visited, 0, sizeof(bool) * (n + 1));
        match += dfs(i);
    }
    return match;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    FOR(i, 0, n) {
        int num; cin >> num;
        FOR(j, 0, num) {
            int w; cin >> w;
            edge[i + 1].push_back(w);
        }
    }

    cout << bipartiteMatch() << "\n";
    return 0;
}