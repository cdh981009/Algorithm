#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 100;
constexpr int M = 10000;
int dp[N+1][M+1];
int n, m, k;

struct airplane {
    int v, c, d;
};

int minTime(int v, int money, const vector<vector<airplane>> &edges) {
    if (money < 0)
        return INF;
    if (v == n)
        return 0;
    int& ref = dp[v][money];
    if (ref != -1)
        return ref;
    ref = INF;
    for (auto tup : edges[v]) {
        int next = tup.v;
        int cost = tup.c;
        int time = tup.d;
        ref = min(ref, minTime(next, money - cost, edges) + time);
    }
    return ref;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    while (tc--) {
        cin >> n >> m >> k;
        memset(dp, -1, sizeof(int)*(N+1)*(M+1));
        vector<vector<airplane>> edges(n + 1);
        FOR(i, 0, k) {
            int u, v, c, d; cin >> u >> v >> c >> d;
            edges[u].push_back({v, c, d});
        }
        int ans = minTime(1, m, edges);
        if (ans >= INF)
            cout << "Poor KCM\n";
        else
            cout << ans << "\n";
    }
    return 0;
}