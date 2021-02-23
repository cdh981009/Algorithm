#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<vector<int>> edges(n, vector<int>());
    vector<int> ans(n-1, -1);
    int ind = -1;
    FOR(i, 0, n-1) {
        int src, dst; cin >> src >> dst;
        src--; dst--;
        edges[src].push_back(i);
        edges[dst].push_back(i);
        ind = (ind == -1 ? ((edges[src].size() >= 3) ? src : ((edges[dst].size() >= 3) ? dst : ind)) : ind);
    }
    int cnt = 0;
    if (ind != -1) {
        for (auto i : edges[ind])
            ans[i] = cnt++;
    }
    for (auto i : ans) {
        i = (i == -1) ? cnt++ : i;
        cout << i << endl;
    }
    
    return 0;
}