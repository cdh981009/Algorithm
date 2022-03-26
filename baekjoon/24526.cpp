#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 10)
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep_(i, a, b) for (int i = (a); i <= (b); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pii>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 201010;
constexpr int M = 100;

ll n, m, ans;
vector<int> edges[N];
int degree[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    rep(i, 0, m) {
        int u, v; cin >> u >> v;
        u--, v--;
        edges[v].push_back(u);
        degree[u]++;
    }

    queue<int> q;

    FOR(i, 0, n) {
        if (degree[i] == 0) q.push(i);
    }

    ans = q.size();

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (auto &nxt: edges[curr]) {
            if (--degree[nxt] == 0) {
                ans += 1;
                q.push(nxt);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}