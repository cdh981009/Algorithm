#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 200;
int n;
int m;
vector<int> sz(N + 1, 1);
vector<int> root(N + 1);

int find(int x) {
    if (root[x] == x)
        return x;
    return root[x] = find(root[x]);
}

bool same(int x, int y) {
    return find(x) == find(y);
}

void unite(int x, int y) {
    if (same(x, y))
        return;
    
    if (sz[x] < sz[y]) swap(x, y);

    root[y] = x;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    FOR(i, 0, n) {
        root[i+1] = i+1;
        FOR(j, 0, n) {
            bool c; cin >> c;
            if (c)
                unite(j+1, i+1);
        }
    }
    int s = -1;
    bool p = true;
    FOR(i, 0, m) {
        int x; cin >> x;
        if (s == -1)
            s = x;
        else
            p = (p & same(x, s));
    }
    cout << (p == true ? "YES" : "NO") << "\n";
    return 0;
}