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
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pii>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 201010;
constexpr int M = 100;

vector<int> edges[N];

int dfs(int x, int p) {
    int ret = 0;

    bool b = true;
    for (auto c : edges[x]) {
        if (c == p) continue;

        int res = dfs(c, x);
        if (res == 0) {
            if (b)
                b = false;
            else
                ret++;
        }
        ret += res;
    }

    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll tc;
    cin >> tc;
    while (tc--) {
        ll n, ans;
        cin >> n;

        FOR(i, 0, n) {
            edges[i].clear();
        }

        FOR(i, 0, n - 1) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }

        if (n == 1) {
            ans = 0;
        } else {
            ans = 1;
            FOR(i, 0, n) {
                if (edges[i].size() >= 3) {
                    ans = dfs(i, -1);
                    break;
                }
            }

        }

        cout << ans << '\n';
    }

    return 0;
}