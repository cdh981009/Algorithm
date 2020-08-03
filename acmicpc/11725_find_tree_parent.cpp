#include <bits/stdc++.h>

using namespace std;

#define INF INT64_MAX
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e5;
int n;
int parent[N + 1];
vector<vector<int>> edges(N + 1);

void parentDfs(int node, int p) {
    parent[node] = p;
    for (auto child : edges[node])
        if (child == p)
            continue;
        else
            parentDfs(child, node);
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    FOR(i, 0, n-1) {
        int v, u;
        cin >> v >> u;
        edges[v].push_back(u);
    }

    parentDfs(1, 0);
    FOR_(i, 2, n)
        cout << parent[i] << "\n";
    return 0;
}