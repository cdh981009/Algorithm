#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 5e5;
constexpr int M = 998244353;

ll ans;
int n, q;
int root[N];
int sz[N];

int find(int x) {
    return root[x] == x ? x : root[x] = find(root[x]);
}

bool same(int x, int y) {
    return find(x) == find(y);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;

    if (sz[x] < sz[y]) swap(x, y);
    sz[x] += sz[y];
    root[y] = x;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    FOR_(i, 0, n) {
        root[i] = i;
        sz[i] = 1;
    }

    FOR(i, 0, q) {
        int x, y;
        cin >> x >> y;
        x--;
        unite(x, y);
    }

    if (same(0, n)) cout << "Yes";
    else cout << "No";
    cout << '\n';

    return 0;
}