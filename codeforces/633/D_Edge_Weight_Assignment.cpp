#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int n;
vector<vector<int>> edges(1e5 + 1, vector<int>());
int subSize[(int)1e5 + 1];
bool oddLevel = false;
bool evenLevel = false;
int maxF = 0;
int minF = 0;

void dfs(int node, int parent, bool even) {
    int &s = subSize[node];
    s = 1;
    int leafChild = 0;
    for (auto child : edges[node]) {
        if (child == parent) continue;
        dfs(child, node, !even);
        s += subSize[child];
        if (subSize[child] == 1)
            leafChild++;
    }
    maxF -= leafChild > 0 ? leafChild - 1 : 0;
    if (s == 1) {
        if (even)
            evenLevel = true;
        else
            oddLevel = true;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 0, n - 1) {
        int v, u; cin >> v >> u;
        edges[v].push_back(u);
        edges[u].push_back(v);
    }
    maxF = n - 1;

    FOR_(i, 1, n) {
        if (edges[i].size() >= 2) {
            dfs(i, 0, true);
            break;
        }
    }
    if (evenLevel && oddLevel)
        minF = 3;
    else
        minF = 1;
    cout << minF << " " << maxF << "\n";
    return 0;
}