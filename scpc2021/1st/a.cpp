#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 101010;

int n;
int ans;
int arr[N];

vector<int> edge[N];
bool visited[N];

void dfs(int x) {
    visited[x] = true;
    FOR(i, 0, edge[x].size()) {
        int o = edge[x][i];
        if (!visited[o]) {
            dfs(o);
        }
    }
}

int main(int argc, char** argv) {
    int T, tc;
    
    freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    for (tc = 0; tc < T; tc++) {
        cin >> n;
        ans = 0;

        memset(edge, 0, sizeof(vector<int>) * n);
        memset(visited, 0, sizeof(bool) * n);

        FOR(i, 0, n) {
            cin >> arr[i];
            int x = i + arr[i];
            if (x < n) {
                edge[i].push_back(x);
                edge[x].push_back(i);
            }
        }

        FOR(i, 0, n) {
            if (!visited[i]) {
                dfs(i);
                ans++;
            }
        }

        cout << "Case #" << tc + 1 << endl;
        cout << ans << endl;
    }

    return 0;
}