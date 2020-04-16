#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int M = 998244353;

vector<vector<int>> edges(3e5+1, vector<int>());
int subtree[(int)3e5+1];
int parent[(int)3e5+1];
int cache[(int)3e5+1][3][2];
 
void dfs(int node) {
    subtree[node] = 1;
    for (auto child : edges[node]) {
        if (child == parent[node]) continue;
        parent[child] = node;
        dfs(child);
        subtree[node] += subtree[child];
    }
}

enum State { UNPICK, CONNECTED, DISCONNECTED };

int count(int node, State state, bool pick) {
    int &ref = cache[node][state][pick];
    if (ref != -1) return ref;
    int res = 1;

    // base caswe
    if (subtree[node] == 1) {

    }

    if (state == UNPICK) {
        for (auto child : edges[node]) {
            if (child == parent[node]) continue;
            int subDiscon = count(child, DISCONNECTED, true) + count(child, DISCONNECTED, false);
            int subUnpick = count(child, UNPICK, false);
            subUnpick %= M;
            subDiscon %= M;
            res *= (subCon + subDiscon) % M;
            res %= M;
        }
    }

    for (auto child : edges[node]) {
        if (child == parent) continue;
        subCon %= M;
        subDiscon %= M;
        res *= (subCon + subDiscon) % M;
        res %= M;
    }

    if (!connectToParent) {
        bool leaf = true;
        int subDisconProduct = 1;
        for (auto child : edges[node]) {
            if (child == parent) continue;
            leaf = false;
            int subDiscon = count(child, node, false, true) + count(child, node, false, false);
            subDiscon %= M;
            subDisconProduct *= subDiscon;
            subDisconProduct %= M;
        }
        //res = (res - subDisconProduct + M) % M;
    }
    cout << "node: " << node << " parent: " << parent << " con " << connectToParent << " pick " << pick << " res " << res << endl; 
    return ref = res;
}


int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(cache, -1, sizeof(int)*(3e5+1)*4);
    memset(parent, 0, sizeof(int)*(3e5+1));

    int n; cin >> n;
    FOR(i, 0, n-1) {
        int x, y; cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    dfs(1);

    int ans = count(1, UNPICK, false);
    ans += count(1, DISCONNECTED, false);
    ans %= M;
    ans += count(1, DISCONNECTED, true);
    ans %= M;
    cout << ans << endl;
    return 0;
}