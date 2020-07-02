#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int n, m, k;
vector<vector<int>> edges(1e5 + 1, vector<int>());
vector<int> numbering(1e5 + 1, -1);
map<int, vector<int>> buckets;
int cnt = 0;

void dfs(int node) {
    if (cnt == k)
        return;
    vector<int> nums;
    for (auto parent : edges[node]) {
        if (numbering[parent] != -1)
            nums.push_back(numbering[parent]);
    }
    sort(nums.begin(), nums.end());
    int mex = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (mex + 1 < nums[i]) {
            break;
        } else {
            mex = nums[i];
        }
    }
    mex++;
    numbering[node] = mex;
    buckets[mex].push_back(node);
    cnt++;
    for (auto child : edges[node]) {
        if (numbering[child] == -1)
            dfs(child);
    }
}

vector<int> llog;
vector<bool> visited(1e5 + 1, false);
int loopPoint;
int looping = 0;
void dfs2(int node, int parent) {
    visited[node] = true;
    for (auto v : edges[node]) {
        if (v != parent && numbering[v] != -1) {
            if (visited[v] && looping == 0) {
                loopPoint = v;
                looping = 1;
            } else {
                dfs2(v, node);
            }
        }
        if (looping != 0)
            break;
    }
    if (looping == 1) {
        llog.push_back(node);
        if (node == loopPoint)
            looping = 2;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;
    FOR(i, 0, m) {
        int v, u; cin >> v >> u;
        edges[v].push_back(u);
        edges[u].push_back(v);
    }
    dfs(1);
    /*
    FOR(i, 0, n) {
        cout << numbering[i] << " ";
    }*/
    if (buckets.size() == 2) {
        cout << 1 << "\n";
        for (auto v : buckets)
            if (v.second.size() >= (k - 1)/2 + 1) {
                FOR(i, 0, (k - 1)/2 + 1) {
                    cout << v.second[i] << " ";
                }
                cout << "\n";
                break;
            }
    } else {
        cout << 2 << "\n";
        dfs2(1, 0);
        cout << llog.size() << "\n";
        for (auto v : llog)
            cout << v << " ";
        cout << "\n";
    }
    return 0;
}