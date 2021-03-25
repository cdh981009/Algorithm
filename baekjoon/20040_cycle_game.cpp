// 20040: 사이클 게임
// https://www.acmicpc.net/problem/20040
#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 1)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 5e5;

int root[N];

int find(int x) {
    return (root[x] == x) ? x : (root[x] = find(root[x]));
}

bool same(int x, int y) {
    return find(x) == find(y);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);

    root[y] = x;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;

    FOR(i, 0, n) {
        root[i] = i;
    }

    int ans = 0;
    FOR(i, 0, m) {
        int x, y; cin >> x >> y;
        if (same(x, y) && ans == 0)
            ans = i + 1;
        unite(x, y);
    }

    cout << ans << '\n';

    return 0;
}