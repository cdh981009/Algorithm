#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e6;
vector<vector<int>> edges(N + 1);
int dp[N + 1][2];

// root가 unpick 이라면 parent는 항상 pick이다.
int pickNode(int root, int parent, bool pick) {
    int& ref = dp[root][pick];
    if (ref != -1)
        return ref;
    ref = pick ? 1 : 0;
    for (auto child : edges[root]) {
        if (child == parent)
            continue;
        // 내가 unpick이면 자식은 항상 pick
        // 내가 pick 이면 자식은 pick 이거나 unpick이다.
        int childPick = pickNode(child, root, true);
        int childUnpick = pick ? pickNode(child, root, false) : INF;
        ref += min(childPick, childUnpick);
    }

    return ref;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof(int) * (N + 1) * 2);
    int n; cin >> n;

    edges[0].push_back(1);
    FOR(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    // 가상의 트리 루트 0을 픽 한 상태 dp를 구한다
    cout << pickNode(0, 0, true) - 1 << "\n";

    return 0;
}