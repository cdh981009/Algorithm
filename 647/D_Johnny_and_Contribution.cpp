#include <bits/stdc++.h>
 
using namespace std;
 
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)
 
int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int blogs, refs; cin >> blogs >> refs;
    vector<vector<int>> edges(blogs + 1, vector<int>());
    FOR(i, 0, refs) {
        int u, v; cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    FOR(i, 0, blogs) {
        int topic; cin >> topic;
        q.push({topic, i + 1});
    }
    vector<int> ans;
    vector<int> written(blogs + 1, 0);
    bool possible = true;
    while (!q.empty() && possible) {
        auto p = q.top();
        q.pop();
        int node = p.second;
        int topic = p.first;
        ans.push_back(node);
        written[node] = topic;
        
        vector<int> s;
        for (auto u : edges[node]) {
            if (written[u] != 0)
                s.push_back(written[u]);
        }
		
		int mex = 0;
		if (!s.empty())
        	sort(s.begin(), s.end());
        for (int i = 0; i < s.size(); ++i) {
			if (s[i] - mex> 1) {
				break;
			} else {
				mex = s[i];
			}
		}
		mex++;
		cout << "node " << node << " topic " << topic << " mex " << mex << endl;
        if (mex != topic) {
            possible = false;
            //cout << "impossible!" << endl;
        }
    }
 
    if (possible) {
        for (auto x : ans)
            cout << x << " ";
        cout << "\n";
    } else {
        cout << -1 << "\n";
    }
    return 0;
}