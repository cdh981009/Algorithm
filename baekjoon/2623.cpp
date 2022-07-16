#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 7)
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

constexpr int N = 1010;
constexpr int M = 8e6 + 10;
constexpr int B = 4e6;

ll n, m;
vi edges[N];
int vst[N];
vi ans;
bool pos = true;

void dfs(int node) {
    vst[node] = 1;
    for (auto nxt : edges[node]) {
        if (vst[nxt] == 0)
            dfs(nxt);
        else if (vst[nxt] == 1)
            pos = false;
    }
    vst[node] = 2;
    ans.push_back(node);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    rep(i, 0, m) {
        int x;
        cin >> x;
        int prev = -1;
        rep(j, 0, x) {
            int y;
            cin >> y;
            y--;
            if (j > 0) edges[y].push_back(prev);
            prev = y;
        }
    }

    rep(i, 0, n) {
        if (vst[i] == 0) dfs(i);
    }

    if (pos)
        rep(i, 0, n) {
            cout << ans[i] + 1 << '\n';
        }
    else
        cout << 0 << '\n';

    return 0;
}