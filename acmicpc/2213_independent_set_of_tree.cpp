#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e4;
vector<vector<int>> edges(N+1);
vector<int> weight(N+1);
int dp[N+1][2];
vector<pair<int, int>> nodeLog[N+1][2];

int isSize(int root, int parent, bool pick) {
    int& ref = dp[root][pick];
    auto& logRef = nodeLog[root][pick];
    if (ref != -1) return ref;

    if (pick) ref = weight[root];
    else ref = 0;

    for (auto child : edges[root]) {
        if (child == parent) continue;
        int childNoPick = isSize(child, root, false);
        int childPick = pick ? -1 : isSize(child, root, true);
        if (childNoPick < childPick) {
            logRef.push_back({child, true});
            ref += childPick;
        } else {
            logRef.push_back({child, false});
            ref += childNoPick;
        }
    }

    return ref;
}

vector<int> lg;
void restoreLog(int node, bool pick) {
    if (pick)
        lg.push_back(node);
    for (auto p : nodeLog[node][pick])
        restoreLog(p.first, p.second);
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof(int) * (N+1) * 2);
    int n; cin >> n;
    FOR(i, 0, n) {
        int u; cin >> u;
        weight[i+1] = u;
    }
    edges[0].push_back(1);
    FOR(i, 0, n-1) {
        int u, v; cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    cout << isSize(0, 0, false) << "\n";
    restoreLog(0, false);
    sort(lg.begin(), lg.end());
    for (auto v : lg)
        cout << v << " ";
    cout << "\n";

    return 0;
}