#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define FOR_(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))

struct Point {
    int x, y;
};

bool cmpX(const Point& p, const Point& q) {
    return p.x < q.x; 
}

bool cmpY(const Point& p, const Point& q) {
    return p.y < q.y;
}

int distance(const Point& p, const Point& q) {
    return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
}

int minDist(vector<Point>& pos, size_t start, size_t end) {
    if (end - start <= 3) {
        int d = INF;
        for (auto i = start; i != end; ++i)
            for (auto j = i + 1; j != end; ++ j)
                d = min(d, distance(pos[i], pos[j]));
        return d;
    }

    auto middle = start + (end - start) / 2;
    int xLine = pos[middle].x;
    int dl, dr;
    dl = minDist(pos, start, middle);
    dr = minDist(pos, middle, end);
    int d = min(dl, dr);

    vector<Point> aux;
    for (auto i = start; i != end; ++i)
        if (abs(pos[i].x - xLine) < d)
            aux.push_back(pos[i]);
    sort(aux.begin(), aux.end(), cmpY);

    for (auto i = aux.begin(); i != aux.end(); ++i)
        for (auto j = i + 1; j != aux.end() && (j->y - i->y < d); ++j)
            d = min(d, distance(*i, *j));

    return d;
}
// O(nlog^2n) solution

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<Point> pos(n);
    FOR(i, 0, n) {
        int x, y; cin >> x >> y;
        pos[i] = {x, y};
    }
    sort(pos.begin(), pos.end(), cmpX);

    cout << minDist(pos, 0, n) << endl;
    return 0;
}