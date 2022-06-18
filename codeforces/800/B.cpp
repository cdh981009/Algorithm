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

vi par;
vector<vector<int>> edges;
vpii range;
vl remain;

int dfs(int node) {
    if (edges[node].empty()) { // leaf
        remain[node] = range[node].se; // 이 만큼 여유가 있다
        return 1;
    } else {
        remain[node] = 0;
        int ret = 0;

        for (auto child : edges[node]) {
            ret += dfs(child);
            remain[node] += remain[child]; // 내 자식들 중 operation을 쓴 자식은 이만큼 여유가 있다
        }

        if (remain[node] >= range[node].fi) {
            // 이 node를 고르지 않고 자식의 operation중 처리 가능
            remain[node] = min(remain[node], (ll)range[node].se);
        } else {
            ret += 1;
            // 이 node를 골라 operation을 써야만 처리 가능
            remain[node] = range[node].se;
        }

        return ret;
    }
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
        ll n; cin >> n;
        edges = vector<vi>(n);
        par = vi(n);
        range = vpii(n);
        remain = vl(n);

        FOR(i, 0, n-1) {
            int x;
            cin >> x;
            par[i + 1] = --x;
            edges[par[i + 1]].push_back(i + 1);
        }
        FOR(i, 0, n) {
            cin >> range[i].fi >> range[i].se;
        }
        cout << dfs(0) << '\n';
    }

    return 0;
}