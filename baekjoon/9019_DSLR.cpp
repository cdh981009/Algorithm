#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e4;

int left(int x) {
    int top = x / (N/10);
    return (x * 10 + top) % N;
}

int right(int x) {
    int bottom = x % 10;
    return (x/10) + bottom * (N/10);
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int tc; cin >> tc;
    while (tc--) {
        int a, b;
        cin >> a >> b;

        vector<bool> visited(N, false);
        vector<pair<int, char>> backtrack(N);
        queue<pair<int, int>> q;
        q.push({a, 0});
        visited[a] = true;

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            int x = curr.first;
            int d = curr.second;
            if (x == b)
                break;
            
            int l[4] = {
                2*x % N,
                x == 0 ? N-1 : x-1,
                left(x),
                right(x)
            };
            char op[4] = {'D', 'S', 'L', 'R'};
            FOR(i, 0, 4) {
                auto y = l[i];
                if (!visited[y]) {
                    visited[y] = true;
                    backtrack[y] = {x, op[i]};
                    q.push({y, d + 1});
                }
            }
        }
        vector<char> reverseLog;
        int curr = b;
        while (true) {
            if (curr == a)
                break;
            reverseLog.push_back(backtrack[curr].second);
            curr = backtrack[curr].first;
        }
        for (auto i = reverseLog.rbegin(); i != reverseLog.rend(); ++i) {
            cout << *i;
        }
        cout << "\n";
    }
    return 0;
}