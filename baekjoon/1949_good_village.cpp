#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e4;
vector<vector<int>> edges(N + 1);
int ppl[N + 1];
int dp[N + 1][2][2];

// root가 pick되었다면 parent는 pick되지 않은 것이다.
// 이때 자식은 모두 unpick되어야 한다.
// root가 unpick되었을 때 parent는 pick이거나 unpick이다.
// parent가 unpick이면 자식중 적어도 하나이상 pick이어야 한다.
// parent가 pick이면 자식은 pick이거나 unpick이다.
int pickNode(int root, int parent, bool parentPick, bool pick) {
    int& ref = dp[root][parentPick][pick];
    if (ref != -1)
        return ref;
    ref = pick ? ppl[root] : 0;

    bool allUnpick = true;
    int bestDiff = -INF;

    for (auto child : edges[root]) {
        if (child == parent)
            continue;
        int childPick = pickNode(child, root, pick, true);
        int childUnpick = pickNode(child, root, pick, false);
        if (pick) {
            ref += childUnpick;
        } else if (parentPick) {
            ref += max(childUnpick, childPick);
        } else {
            if (childPick >= childUnpick) {
                allUnpick = false;
                ref += childPick;
            } else {
                ref += childUnpick;
                // childPick < childUnpick 이므로 항상 음수
                bestDiff = max(bestDiff, childPick - childUnpick);
            }
        }
    }

    // root, parent가 unpick이면 자식중 적어도 하나이상 pick이어야 한다.
    // 가장 적게 손해 보는 자식 하나를 택한다.
    if (!pick && !parentPick && allUnpick) {
        ref += bestDiff;
    }

    return ref;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof(int) * (N + 1) * 2 * 2);
    int n; cin >> n;
    FOR(i, 0, n) {
        int x; cin >> x;
        ppl[i+1] = x;
    }
    edges[0].push_back(1);
    FOR(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    // 가상의 트리 루트 0의 부모는 pick이고 자신은 unpick
    // 이므로 실제 루트 1은 pick이거나 unpick이다.
    cout << pickNode(0, 0, true, false) << "\n";

    return 0;
}