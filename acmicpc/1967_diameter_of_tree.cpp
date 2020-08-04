#include <bits/stdc++.h>

using namespace std;

#define INF INT64_MAX
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e5;
int n;
int d = 0;
vector<vector<pair<int, int>>> edges(N + 1);

int computeDiameterDfs(int node, int parent) {
    int first = 0;
    int second = 0;
    for (auto edge : edges[node]) {
        int child = edge.first;
        int weight = edge.second;
        if (child == parent) continue;
        int subHeight = computeDiameterDfs(child, node) + weight;
        if (first < subHeight) {
            second = first;
            first = subHeight;
        } else if (second < subHeight) {
            second = subHeight;
        }
    }
    d = max(d, first + second);
    return first;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    FOR(i, 0, n-1) {
        int v, u, w;
        cin >> v >> u >> w;
        edges[v].push_back({u, w});
        edges[u].push_back({v, w});
    }

    computeDiameterDfs(1, 0);
    cout << d << "\n";
    return 0;
}