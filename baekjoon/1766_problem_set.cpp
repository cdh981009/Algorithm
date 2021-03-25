#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 32e3;
int indegree[N + 1];
vector<int> edge[N + 1];
priority_queue<int, vector<int>, greater<int>> q;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    FOR(i, 0, m) {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        ++indegree[y];
    }

    FOR_(i, 1, n) {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty()) {
        auto node = q.top();
        q.pop();
        for (auto child : edge[node])
            if (--indegree[child] == 0)
                q.push(child);
        cout << node << " ";
    }
    cout << "\n";

    return 0;
}