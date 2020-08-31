#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 32e3;
vector<vector<int>> edge(N + 1);
vector<bool> visited(N + 1, false);
vector<int> stck;

void dfs(int node) {
    visited[node] = true;
    for (auto next : edge[node]) {
        if (!visited[next])
            dfs(next);
    }
    stck.push_back(node);
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    FOR(i, 0, m) {
        int s, d;
        cin >> s >> d;
        edge[s].push_back(d);
    }

    FOR_(i, 1, n) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    for (auto i = stck.rbegin(); i != stck.rend(); ++i) {
        cout << *i << " ";
    }
    cout << "\n";

    return 0;
}