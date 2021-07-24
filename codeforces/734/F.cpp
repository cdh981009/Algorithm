#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 101;
constexpr int M = 1e9 + 7;

ll ans;
int n, k;
vector<int> edges[N];
int depth[N][N];
int arr[N];
int dp[N][N];

void dfs(int cur, int par) {
    memset(depth[cur], 0, sizeof(int) * n);
    depth[cur][0] = 1;

    FOR(i, 0, edges[cur].size()) {
        int nxt = edges[cur][i];
        if (nxt == par)
            continue;
        dfs(nxt, cur);
        FOR(j, 1, n) {
            depth[cur][j] += depth[nxt][j - 1];
        }
    }
}

void solve(int root) {
    if (edges[root].size() < k)
        return;

    dfs(root, -1);

    FOR(dist, 0, n) {
        FOR(i, 0, edges[root].size()) {
            int child = edges[root][i];
            int x = depth[child][dist];
            arr[i] = x;
        }
        memset(dp, 0, sizeof(int) * N * N);
        FOR(i, 0, edges[root].size()) {
            dp[i][0] = 1;
        }
        FOR_(i, 1, edges[root].size()) {
            FOR_(j, 1, min(i, k)) {
                dp[i][j] = (dp[i - 1][j] + (ll) arr[i - 1] * dp[i - 1][j - 1]) % M;
            }
        }
        ans += dp[edges[root].size()][k];
        ans %= M;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n >> k;
        memset(edges, 0, sizeof(vector<int>) * N);
        ans = 0;

        FOR(i, 0, n - 1) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        if (k == 2) {
            ans = n * (n - 1) / 2;
            ans %= M;
        } else {
            FOR(i, 0, n) {
                solve(i);
            }
        }

        cout << ans << '\n';
    }
    return 0;
}