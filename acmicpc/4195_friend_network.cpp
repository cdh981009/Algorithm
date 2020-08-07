#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 2e5;
vector<int> sz(N + 1);
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
    x = find(x);
    y = find(y);

    if (x == y)
        return;
    
    if (sz[x] < sz[y]) swap(x, y);

    root[y] = x;
    sz[x] += sz[y];
}

int size(int x) {
    return sz[find(x)];
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int tc; cin >> tc;
    while (tc--) {
        int f; cin >> f;
        map<string, int> m;
        FOR_(i, 1, 2*f) {
            sz[i] = 1;
            root[i] = i;
        }
        FOR(i, 0, f) {
            string s1, s2; cin >> s1 >> s2;
            if (m.count(s1) == 0)
                m[s1] = m.size() + 1;
            if (m.count(s2) == 0)
                m[s2] = m.size() + 1;
            unite(m[s1], m[s2]);
            cout << size(m[s1]) << "\n";
        }
    }
    return 0;
}