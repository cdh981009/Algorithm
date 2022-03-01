#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

constexpr int N = 100;
constexpr int M = 998244353;

vector<bool> visited;

int dfs(vi& a, int node, int p) {
    p ^= 1;
    visited[node] = true;

    int nxt = a[node];
    if (visited[nxt]) return (p ^ 1);
    else return dfs(a, nxt, p);
}

int parity(vi& a) {
    int ret = 0;
    int n = a.size();
    visited = vector<bool>(n);

    FOR(i, 0, n) {
        if (!visited[i]);
            ret ^= dfs(a, i, 0);
    }

    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    vector<int> a, b;
    cin >> n;
    a = vi(n);
    b = vi(n);

    FOR(i, 0, n) {
        int x; cin >> x;
        a[i] = --x;
    }

    FOR(i, 0, n) {
        int x; cin >> x;
        b[i] = --x;
    }

    // counting inversion
    vi aux(n);
    int acnt, bcnt;
    acnt = parity(a);
    bcnt = parity(b);

    bool pos = true;
    if (acnt != bcnt) pos = false;

    cout << (pos ? "Possible" : "Impossible") << '\n';
;
    return 0;
}