#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;
    vector<bool> visited(2e5 + 1, false);
    queue<pair<int, int>> q;
    q.push({n, 0});
    visited[n] = true;
    int ans = 0;
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        int x = curr.first;
        int d = curr.second;
        if (x == k) {
            ans = d;
            break;
        } else {
            auto l = {x-1, x+1, 2*x};
            for (auto y : l) {
                if (y >= 0 && y <= 2e5 && !visited[y]) {
                    visited[y] = true;
                    q.push({y, d + 1});
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}