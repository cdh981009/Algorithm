#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1000;

vector<int> cost(N + 1);
vector<vector<int>> back(N + 1);
vector<vector<int>> edge(N + 1);
int dp[N + 1];
bool visited[N + 1];
vector<int> topological;

void dfs(int node) {
    visited[node] = true;
    for (auto child : edge[node]) {
        if (!visited[child])
            dfs(child);
    }
    topological.push_back(node);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        back.clear();
        edge.clear();
        topological.clear();
        memset(visited, 0, sizeof(bool) * (N + 1));
        int n, k;
        cin >> n >> k;
        back.resize(n + 1, vector<int>());
        edge.resize(n + 1, vector<int>());
        FOR(i, 0, n) {
            int x;
            cin >> x;
            cost[i + 1] = x;
        }
        FOR(i, 0, k) {
            int x, y;
            cin >> x >> y;
            back[y].push_back(x);
            edge[x].push_back(y);
        }
        int w;
        cin >> w;
        FOR_(i, 1, n) {
            if (!visited[i])
                dfs(i);
        }
        for (auto i = topological.rbegin(); i != topological.rend(); ++i) {
            auto node = *i;
            auto& ref = dp[node];
            ref = 0;
            for (auto parent : back[node]) {
                ref = max(ref, dp[parent]);
            }
            ref += cost[node];
        }
        cout << dp[w] << "\n";
    }

    return 0;
}