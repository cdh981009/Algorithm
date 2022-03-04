#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pii>;

constexpr int N = 201010;  // 10;
constexpr int M = 100;

int n;
vi edges[N];
vi anses[N][2];
pii dp[N][2];
bool mem[N][2];
int gc, sum;
int ans[N];

pii dfs(int node, int p, bool col) {
    auto& memd = mem[node][col];
    auto& currans = anses[node][col];
    if (memd) return dp[node][col];
    memd = true;

    if (edges[node].size() == 1 && p != -1) {  // leaf
        if (col == 1) return {1, -1};
        else          return {0, 0};
    }

    pii ret = {0, 0};
    if (col == 1) {
        ret = {1, -(int)edges[node].size()};
    }

    FOR(i, 0, edges[node].size()) {
        int nxt = edges[node][i];
        if (nxt == p) continue;

        if (col == 0) {  // don't color this
            // color child
            pii res1 = dfs(nxt, node, true);

            // don't color child
            pii res2 = dfs(nxt, node, false);

            if (res1 > res2) {
                currans.push_back(true);
                ret.fi += res1.fi;
                ret.se += res1.se;
            } else {
                currans.push_back(false);
                ret.fi += res2.fi;
                ret.se += res2.se;
            }
        } else {  // color this
            pii res = dfs(nxt, node, false);
            ret.fi += res.fi;
            ret.se += res.se;
            currans.push_back(false);
        }
    }

    return dp[node][col] = ret;
}

void dfs2(int node, int p, bool col) {
    if (col == true) {
        gc++;
        ans[node] = edges[node].size();
    } else {
        ans[node] = 1;
    }

    int cnt = 0;
    FOR(i, 0, edges[node].size()) {
        int nxt = edges[node][i];
        if (nxt == p) continue;
        dfs2(nxt, node, anses[node][col][cnt++]);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    if (n == 2) {
        gc = 2;
        sum = 2;
        ans[0] = ans[1] = 1;
    } else {
        int root = 0;
        FOR(i, 0, n) {
            if (edges[i].size() == 1) {
                root = i;
                break;
            }
        }

        auto res1 = dfs(root, -1, true);

        dfs2(root, -1, true);

        FOR(i, 0, n) sum += ans[i];
    }

    cout << gc << ' ' << sum << '\n';
    FOR(i, 0, n) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}