#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

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

int minDist(const vector<Point>& pos, vector<Point>& ySort, vector<Point>& aux, size_t start, size_t end) {
    if (end - start <= 3) {
        int d = INF;
        for (auto i = start; i < end; ++i) {
            ySort[i] = pos[i];
            for (auto j = i + 1; j < end; ++j)
                d = min(d, distance(pos[i], pos[j]));
        }
        sort(ySort.begin() + start, ySort.begin() + end, cmpY);
        return d;
    }

    size_t middle = (start + end) / 2;
    int dl, dr;
    dl = minDist(pos, ySort, aux, start, middle);
    dr = minDist(pos, ySort, aux, middle, end);
    int d = min(dl, dr);

    // ySortL and R come out as sorted, hence merging takes O(n) time
    size_t itL = start;
    size_t itR = middle;
    size_t it = start;
    while (itL < middle && itR < end) {
        if (ySort[itL].y < ySort[itR].y)
            aux[it++] = ySort[itL++];
        else
            aux[it++] = ySort[itR++];
    }
    while (itL < middle)
        aux[it++] = ySort[itL++];
    while (itR < end)
        aux[it++] = ySort[itR++];

    FOR(i, start, end)
        ySort[i] = aux[i];

    int midPoint = pos[middle].x;
    vector<Point> candidates;
    for (auto i = start; i != end; ++i)
        if (abs(ySort[i].x - midPoint) < d)
            candidates.push_back(ySort[i]);

    for (auto i = candidates.begin(); i != candidates.end(); ++i) 
        for (auto j = i + 1; j != candidates.end() && (j->y - i->y < d); ++j)
            d = min(d, distance(*i, *j));

    return d;
}
// O(nlogn) solution

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
    vector<Point> ySort(n);
    vector<Point> aux(n);
    cout << minDist(pos, ySort, aux, 0, n) << endl;
    return 0;
}