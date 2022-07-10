#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep_(i, a, b) for (int i = (a); i <= (b); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)
#define printYN(pos) cout << (pos ? "YES" : "NO") << '\n'
#define printPOS(pos) cout << (pos ? "POSSIBLE" : "IMPOSSIBLE") << '\n'

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 2530;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    for (int testcase = 1; testcase <= tc; ++testcase) {
        cout << "Case #" << testcase << ": ";

        ll n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> edges(n, vector<int>());
        set<int> visited;
        rep(i, 0, m) {
            int u, v; cin >> u >> v;
            u--, v--;
            edges[v].push_back(u);
        }

        int ans = 0;
        rep(i, 0, n) {
            visited.clear();

            queue<int> q;
            q.push(i);
            visited.insert(i);
            int cnt = 1;

            while (!q.empty()) {
                int c = q.front();
                q.pop();
                for (auto nxt : edges[c]) {
                    if (visited.count(nxt)) continue;
                    cnt++;
                    q.push(nxt);
                    visited.insert(nxt);
                    if (cnt > k) break;
                }

                if (cnt > k) break;
            }

            if (cnt > k) ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}