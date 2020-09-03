#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e5;
vector<vector<int>> edge;
bool hasParent[N + 1];
int ans;

int dfs(int node, int a, int b) {
    int res = 0;
    if (node == a || node == b)
        res = 1;
    for (auto child : edge[node])
        res += dfs(child, a, b);
    if (ans == 0 && res == 2)
        ans = node;
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        memset(hasParent, false, sizeof(bool) * (N+1));
        edge.clear();
        ans = 0;
        int n;
        cin >> n;
        edge.resize(n + 1);
        FOR(i, 0, n - 1) {
            int a, b; cin >> a >> b;
            edge[a].push_back(b);
            hasParent[b] = true;
        }
        int a, b; cin >> a >> b;
        FOR_(i, 1, n) {
            if (!hasParent[i])
                dfs(i, a, b);
        }
        cout << ans << "\n";
    }

    return 0;
}