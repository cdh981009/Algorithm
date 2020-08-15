#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using point = pair<int, int>;
using line = pair<point, point>;

constexpr int N = 3e3;
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

bool intersect(const line& l1, const line& l2) {
    vector<point> p = {l1.first, l1.second, l2.first, l2.second};
    auto ccw = [&p](int a, int b, int c) -> int {
        point l = {p[b].first - p[a].first, p[b].second - p[a].second};
        point r = {p[c].first - p[b].first, p[c].second - p[b].second};
        long long res = l.first * r.second - r.first * l.second;
        return (0 < res) - (res < 0);
    };

    int a = ccw(0, 1, 2) * ccw(0, 1, 3);
    int b = ccw(2, 3, 0) * ccw(2, 3, 1);

    bool res;
    if (p[0] == p[2] ||
        p[0] == p[3] ||
        p[1] == p[2] ||
        p[1] == p[3]) { // 한 꼭짓점에서 만난다
        res = true;
    } else if (a == 0 && b == 0) { // 일직선상에 있다
        vector<point> aux(p);
        sort(aux.begin(), aux.end());
        if (aux[0] == p[0] || aux[0] == p[1])
            res = (aux[1] != p[0] && aux[1] != p[1]);
        else
            res = (aux[1] != p[2] && aux[1] != p[3]);
    } else { // 교차한다
        res = (a <= 0 && b <= 0);
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<line> l;
    l.reserve(n);
    FOR(i, 0, n) {
        root[i] = i;
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        l.push_back({{x1, y1}, {x2, y2}});
    }

    FOR(i, 0, n) {
        FOR(j, i+1, n) {
            if (same(i, j)) continue;
            if (intersect(l[i], l[j]))
                unite(i, j);
        }
    }

    int maxVal = 0;
    vector<int> groups;
    FOR(i, 0, n) {
        maxVal = max(maxVal, size(i));
        groups.push_back(find(i));
    }
    sort(groups.begin(), groups.end());
    int cnt = distance(groups.begin(), unique(groups.begin(), groups.end()));
    cout << cnt << "\n" << maxVal << "\n";
    return 0;
}