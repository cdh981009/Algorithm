#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e2;
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

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    
    using pdd = pair<double, double>;
    int n; cin >> n;
    FOR(i, 0, n) {
        root[i] = i;    
    }
    vector<pdd> p;
    FOR(i, 0, n) {
        double x, y; cin >> x >> y;
        p.push_back({x, y});
    }
    vector<pair<double, pair<int, int>>> edges;
    auto dist = [](const pdd& l, const pdd& r) -> double {
        double i = (l.first - r.first);
        double j = (l.second - r.second);
        return sqrt(i*i + j*j);
    };

    FOR(i, 0, n) {
        FOR(j, i + 1, n) {
            double w = dist(p[i], p[j]);
            edges.push_back({w, {i, j}});
        }
    }

    sort(edges.begin(), edges.end());
    int cnt = 0;
    double ans = 0;
    for (auto i = edges.begin(); i != edges.end() && cnt < n; ++i) {
        auto w = i->first;
        auto u = i->second.first;
        auto v = i->second.second;
        if (!same(u, v)) {
            ans += w;
            cnt++;
            unite(u, v);
        }
    }
    cout << ans << "\n";
    return 0;
}