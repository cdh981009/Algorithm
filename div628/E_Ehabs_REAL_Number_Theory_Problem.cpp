#include <bits/stdc++.h>
 
using namespace std;
 
#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)
 
constexpr int MAX_N = 1e6;
int minFactor[MAX_N + 1];
 
void sieve() {
    int n = MAX_N;
    minFactor[0] = minFactor[1] = 1;
    for (int i = 2; i <= n; ++i)
        minFactor[i] = i;
    int sqrtn = int(sqrt(n));
    for (int i = 2; i <= sqrtn; ++i) {
        if (minFactor[i] == i) {
            for (int j = i*i; j <= n; j += i)
                if (minFactor[j] == j)
                    minFactor[j] = i;
        }
    }
}
 
vector<int> factor(int n) {
    vector<int> ret;
    while(n > 1) {
        if (ret.empty() || ret.back() != minFactor[n])
            ret.push_back(minFactor[n]);
        else
            ret.pop_back();
        n /= minFactor[n];
    }
    return ret;
}
 
vector<vector<int>> edges(MAX_N + 1, vector<int>());
  vector<pair<bool, int>> visited(MAX_N + 1);
int ans = INF;
 
void bfs_cycle(int start) {
    if (edges[start].empty())
        return;
    visited.assign(MAX_N + 1, {false, 0});
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = {true, 0};
    while (!q.empty()) {
        int curr = q.front().first;
        int prev = q.front().second;
        //cout << "curr " << curr << endl;
        q.pop();
        for (auto next : edges[curr]) {
            if (next < start || next == prev) continue;
            //cout << "next " << next << endl;
            if (visited[next].first == true) {
                //cout << "curr " << visited[curr].second << " next " << visited[next].second << endl;;
                ans = min(ans, visited[curr].second + visited[next].second + 1);
            } else {
                q.push({next, curr});
                visited[next] = {true, visited[curr].second + 1};
            }
        }
    }
}
 
vector<pair<int, int>> uniqueEdges;
int main() {
    //freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    sieve();
    int len; cin >> len;
    FOR(i, 0, len) {
        int a; cin >> a;
        vector<int> nodes = factor(a);
        if (nodes.empty()) {
            ans = 1;
        } else if (nodes.size() == 1) {
            edges[1].push_back(nodes[0]);
            edges[nodes[0]].push_back(1);
            uniqueEdges.push_back({1, nodes[0]});
            uniqueEdges.push_back({nodes[0], 1});
        } else {
            edges[nodes[0]].push_back(nodes[1]);
            edges[nodes[1]].push_back(nodes[0]);
            uniqueEdges.push_back({nodes[0], nodes[1]});
            uniqueEdges.push_back({nodes[1], nodes[0]});
        }
    }
    
    if (ans == INF) {
        int orgSize = uniqueEdges.size();
        sort(uniqueEdges.begin(), uniqueEdges.end());
        int unqSize = unique(uniqueEdges.begin(), uniqueEdges.end()) - uniqueEdges.begin();
        //cout << orgSize << " " <<  unqSize << endl;
        if (orgSize != unqSize)
            ans = 2;
    }
 
    for (auto v : edges)
        sort(v.begin(), v.end());
        
    if (ans == INF) {
        for (int i = 1; i * i <= MAX_N; ++i) {
            if (minFactor[i] == i)
                bfs_cycle(i);
        }
    }
 
    ans = (ans == INF) ? -1 : ans;
    cout << ans << "\n";
    return 0;
}