#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int M = 998244353;

vector<vector<int>> edges(3e5+1, vector<int>());
int subtree[(int)3e5+1];
int parent[(int)3e5+1];
long long cache[(int)3e5+1][3][2];
 
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

long long count(int node, State state, bool pick) {
    long long &ref = cache[node][state][pick];
    if (ref != -1) return ref;
    long long res = 1;

    // base case
    if (subtree[node] == 1) {
        if (state == UNPICK)
            return ref = 1;
        if (state == CONNECTED)
            return ref = 1;
        if (state == DISCONNECTED)
            return ref = 0;
    }

    if (state == UNPICK) {
        for (auto child : edges[node]) {
            if (child == parent[node]) continue;
            long long subDiscon = count(child, DISCONNECTED, true) + count(child, DISCONNECTED, false);
            long long subUnpick = count(child, UNPICK, false);
            subUnpick %= M;
            subDiscon %= M;
            res *= (subDiscon + subUnpick) % M;
            res %= M;
        }
    } else {
        // state DISCONNECTED asserts at least one connection with its child
        long long minus = 1;
        for (auto child : edges[node]) {
            if (child == parent[node]) continue;
            long long subCon = (pick ? 0 : count(child, CONNECTED, true)) + count(child, CONNECTED, false);
            long long subDiscon = count(child, DISCONNECTED, true) + count(child, DISCONNECTED, false);
            long long subUnpick = count(child, UNPICK, false);
            // cout << "node " << node << " " << subCon << " " << subDiscon << " " << subUnpick << endl;
            subCon %= M;
            subDiscon %= M;
            subUnpick %= M;
            res *= (subCon + subDiscon + subUnpick) % M;
            res %= M;
            minus *= (subDiscon + subUnpick) % M;
            minus %= M;
        }
        if (state == DISCONNECTED) 
            res = (res - minus + M) % M;
    }
    string stateStr[3] = {"unpick", "connected", "disconnected"};
    //cout << "node: " << node << " parent: " << parent[node] << " state " << stateStr[state]<< " pick " << pick << " res " << res << endl; 
    return ref = res;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(cache, -1, sizeof(long long)*(3e5+1)*6);
    memset(parent, 0, sizeof(int)*(3e5+1));

    int n; cin >> n;
    FOR(i, 0, n-1) {
        int x, y; cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    dfs(1);

    int ans = count(1, UNPICK, false) - 1 + M;
    ans %= M;
    ans += count(1, DISCONNECTED, false);
    ans %= M;
    ans += count(1, DISCONNECTED, true);
    ans %= M;
    cout << ans<< endl;
    return 0;
}