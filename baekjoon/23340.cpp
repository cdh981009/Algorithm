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

constexpr int N = 201010;
constexpr int M = 100;

int n;

struct Edge {
    ll d, w;
};

vector<Edge> edges[N];

// node와 par의 edge부터 시작하는 strictly increasing path갯수
ll down[N]; 
// node와 par의 edge로 끝나는 strictly increasing path갯수
ll up[N]; 

ll dfs(int node, int par, ll pw) {
    rep(i, 0, edges[node].size()) {
        if (edges[node][i].d == par) {
            swap(edges[node][i], edges[node].back());
            edges[node].pop_back();
            break;
        }
    }

    sort(edges[node].begin(), edges[node].end(), [](auto& l, auto& r) {
        return l.w < r.w;
    });

    // ret := 내 subtree에 담긴 path 갯수
    ll ret = 0;
    ll ecnt = edges[node].size();

    down[node] = up[node] = 1;

    rep(i, 0, ecnt) {
        auto &[child, w] = edges[node][i];
        ret += dfs(child, node, w);

        if (pw < w) // down 연결
            down[node] += down[child];

        if (pw > w) // up 연결
            up[node] += up[child];

        ret += up[child] + down[child];
    }

    // 자식에서 올라와서 자식으로 내려가는 path 갯수를 세어주어야함
    // 내려가는 path 하나에 대해 올라오는 path중 weight가 작은 것들을 앞에 연결해서
    // 새로운 path를 만드는 가짓수를 셈
    ll psum = 0;
    ll j = -1;
    rep(i, 0, ecnt) {
        auto &[child, w] = edges[node][i];

        while (j + 1 < ecnt && edges[node][j + 1].w < w) {
            j++;
            psum += up[edges[node][j].d];
        }

        ret += psum * down[child];
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

    cin >> n;
    rep(i, 0, n - 1) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }

    ll ans = dfs(1, 0, -1);

    cout << ans << '\n';

    return 0;
}