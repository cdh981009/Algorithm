#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 5e5;
int n, m, s, p;

int atm[N + 1];
vector<int> edges[N + 1];
vector<int> backEdges[N + 1];
bool visited[N + 1];
bool restaurant[N + 1];

vector<int> dfsEndStack;
int node2Component[N + 1];
vector<int> componentEdges[N];
int componentAtmSum[N];
bool componentRestaurant[N];
pair<int, bool> cache[N];

int componentCnt = 0;

void dfs(int node) {
    visited[node] = true;
    for (auto next : edges[node]) {
        if (!visited[next])
            dfs(next);
    }
    dfsEndStack.push_back(node);
}

void dfsGetScc(int node) {
    visited[node] = true;
    for (auto back : backEdges[node]) {
        if (!visited[back])
            dfsGetScc(back);
    }
    node2Component[node] = componentCnt;
    componentAtmSum[componentCnt] += atm[node];
    componentRestaurant[componentCnt] |= restaurant[node];
}

// component node에서 시작해서
// 어떤 레스토랑까지 이동하면서 인출 할 수 있는 현금의 최대 액수를 계산한다.
pair<int, bool> dfsComputeMoney(int component) {
    if (visited[component] == true) {
        return cache[component];
    }
    visited[component] = true;

    bool canGetToRestaurant = componentRestaurant[component];
    int money = 0;

    for (auto nextComponent : componentEdges[component]) {
        auto res = dfsComputeMoney(nextComponent);
        money = max(money, res.first);
        canGetToRestaurant |= res.second;
    }

    money = (canGetToRestaurant ? money + componentAtmSum[component] : 0);
    return component[cache] = {money, canGetToRestaurant};
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    FOR(i, 0, m) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        backEdges[v].push_back(u);
    }

    FOR(i, 0, n) {
        int x;
        cin >> x;
        atm[i + 1] = x;
    }

    cin >> s >> p;
    FOR(i, 0, p) {
        int x;
        cin >> x;
        restaurant[x] = true;
    }

    // make stack
    dfsEndStack.reserve(n);
    FOR_(i, 1, n) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    FOR_(i, 1, n) {
        visited[i] = false;
    }

    // make scc graph
    FOR(i, 0, dfsEndStack.size()) {
        auto node = dfsEndStack[dfsEndStack.size() - 1 - i];
        if (!visited[node]) {
            dfsGetScc(node);
            componentCnt++;
        }
    }

    FOR_(node, 1, n) {
        for (auto next : edges[node]) {
            if (node2Component[node] != node2Component[next])
                componentEdges[node2Component[node]].push_back(node2Component[next]);
        }
    }

    FOR(i, 0, componentCnt) {
        visited[i] = false;
    }

    cout << dfsComputeMoney(node2Component[s]).first << "\n";

    return 0;
}