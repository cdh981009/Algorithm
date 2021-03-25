// 14751: Leftmost Segment
// https://www.acmicpc.net/problem/14751
#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 5)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

struct Vec2 {
    double x, y;

    Vec2(double x = 0.0, double y = 0.0) : x(x), y(y) {}
};

Vec2 operator+(const Vec2& l, const Vec2& r) {
    return Vec2(l.x + r.x, l.y + r.y);
}

Vec2 operator-(const Vec2& l, const Vec2& r) {
    return Vec2(l.x - r.x, l.y - r.y);
}

Vec2 operator*(double c, const Vec2& v) {
    return {c * v.x, c * v.y};
}

double cross(const Vec2& l, const Vec2& r) {
    return l.x * r.y - l.y * r.x;
}

double dot(const Vec2& l, const Vec2& r) {
    return l.x * r.x + l.y * r.y;
}

struct Line {
    Vec2 point;
    Vec2 dir;

    Line(double x0, double y0, double x1, double y1) {
        point = {x0, y0};
        dir = {x1 - x0, y1 - y0};
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int maxX, minX;
    cin >> maxX >> minX;
    int n;
    cin >> n;

    vector<Line> lines;
    lines.reserve(n);
    FOR(i, 0, n) {
        int upperY, lowerY;
        cin >> upperY >> lowerY;
        lines.push_back(Line(maxX, upperY, minX, lowerY));
    }

    vector<int> perm(n);
    FOR(i, 0, n) {
        perm[i] = i;
    }

    sort(perm.begin(), perm.end(), [&](int i, int j) {
        // dx is always the same
        return lines[i].dir.y == lines[j].dir.y ? lines[i].point.y < lines[j].point.y : lines[i].dir.y < lines[j].dir.y;
    });

    auto crossX = [&](int i, int j) -> double {
        const Line& l = lines[i];
        const Line& r = lines[j];

        double s = cross(l.dir, l.point - r.point) / cross(l.dir, r.dir);

        return (s * l.dir + l.point).x;
    };

    vector<int> hull;

    FOR(i, 0, n) {
        const auto& curr = perm[i];

        if (!hull.empty() &&
                lines[curr].dir.y == lines[hull.back()].dir.y) {
            continue;
        }

        while (hull.size() >= 2 &&
                crossX(curr, *(hull.end() - 1)) <= crossX(*(hull.end() - 1), *(hull.end() - 2)) + DBL_EPSILON) {
            hull.pop_back();
        }

        hull.push_back(curr);
    }

    int q;
    cin >> q;
    vector<pair<double, int>> queries(q);
    FOR(i, 0, q) {
        double x;
        cin >> x;
        queries[i] = {x, i};
    }
    sort(queries.begin(), queries.end());

    vector<int> ans(q);
    int ind = 0;
    for (const auto& p : queries) {
        while (ind + 1 < hull.size() && crossX(hull[ind], hull[ind + 1]) <= p.first + DBL_EPSILON) {
            ind++;
        }
        ans[p.second] = hull[ind];
    }

    for (auto x : ans)
        cout << x + 1 << '\n';

    return 0;
}