#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e5;
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
    x = find(x);
    y = find(y);

    if (x == y)
        return;

    if (sz[x] < sz[y])
        swap(x, y);

    root[y] = x;
    sz[x] += sz[y];
}

int size(int x) {
    return sz[find(x)];
}

struct point {
    int x[3];
    int ind;
};

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    FOR(i, 0, n) {
        root[i] = i;
    }
    vector<point> p;
    FOR(i, 0, n) {
        int x, y, z;
        cin >> x >> y >> z;
        p.push_back({x, y, z, i});
    }

    vector<pair<int, pair<int, int>>> edges;

    FOR(i, 0, 3) {
        sort(p.begin(), p.end(),
                [i](const point& lhs, const point& rhs)
                        -> bool { return lhs.x[i] < rhs.x[i]; });

        FOR(j, 0, p.size() - 1) {
            edges.push_back({abs(p[j].x[i] - p[j + 1].x[i]), {p[j].ind, p[j+1].ind}});
        }
    }
    long long ans = 0;
    sort(edges.begin(), edges.end());
    for (auto i = edges.begin(); i != edges.end() && size(0) < n; ++i) {
        auto w = i->first;
        auto u = i->second.first;
        auto v = i->second.second;
        if (!same(u, v)) {
            ans += w;
            unite(u, v);
        }
    }

    cout << ans << "\n";
    return 0;
}