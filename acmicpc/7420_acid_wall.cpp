// 7420: 맹독 방벽
// https://www.acmicpc.net/problem/7420
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

struct Vector2 {
    int x, y;

    Vector2(int x = 0, int y = 0) : x(x), y(y) {}

    Vector2& operator+=(const Vector2& r) {
        x += r.x;
        y += r.y;
        return *this;
    }

    Vector2& operator-=(const Vector2& r) {
        x -= r.x;
        y -= r.y;
        return *this;
    }

    Vector2 operator-() {
        return Vector2(-x, -y);
    }
};

bool operator==(const Vector2& l, const Vector2& r) {
    return (l.x == r.x && l.y == r.y);
}

Vector2 operator+(const Vector2& l, const Vector2& r) {
    return Vector2(l.x + r.x, l.y + r.y);
}

Vector2 operator-(const Vector2& l, const Vector2& r) {
    return Vector2(l.x - r.x, l.y - r.y);
}

long long cross(const Vector2& l, const Vector2& r) {
    return (long long)l.x * r.y - (long long)l.y * r.x;
}

long long ccw(const Vector2& l, const Vector2& m, const Vector2& r) {
    return (long long)(m.x - l.x) * (r.y - m.y) - (long long)(m.y - l.y) * (r.x - m.x);
}

long long dot(const Vector2& l, const Vector2& r) {
    return (long long)l.x * r.x + (long long)l.y * r.y;
}

long long sqrAbs(const Vector2& v) {
    return (long long)v.x * v.x + (long long)v.y * v.y;
}

long long sqrDist(const Vector2& a, const Vector2& b) {
    return sqrAbs(a - b);
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, l, x, y;
    vector<Vector2> points;

    cin >> n >> l;
    points.reserve(n);
    FOR(i, 0, n) {
        cin >> x >> y;
        points.push_back(Vector2(x, y));
    }

    sort(points.begin(), points.end(), [](const Vector2& l, const Vector2& r) {
        return (l.x != r.x) ? l.x < r.x : l.y < r.y;
    });

    // getting convex hull
    vector<Vector2> upperStack, lowerStack;
    FOR(i, 0, n) {
        while (upperStack.size() >= 2 &&
                ccw(
                        upperStack[upperStack.size() - 2],
                        upperStack[upperStack.size() - 1],
                        points[i]) >= 0) {
            upperStack.pop_back();
        }
        upperStack.push_back(points[i]);

        while (lowerStack.size() >= 2 &&
                ccw(
                        lowerStack[lowerStack.size() - 2],
                        lowerStack[lowerStack.size() - 1],
                        points[i]) <= 0) {
            lowerStack.pop_back();
        }
        lowerStack.push_back(points[i]);
    }
    double len = 0;
    FOR(i, 0, upperStack.size() - 1) {
        auto& a = upperStack[i];
        auto& b = upperStack[i + 1];
        len += sqrt(sqrDist(a, b));
    }
    FOR(i, 0, lowerStack.size() - 1) {
        auto& a = lowerStack[i];
        auto& b = lowerStack[i + 1];
        len += sqrt(sqrDist(a, b));
    }
    len += 3.1415926535897 * 2 * l;
    cout << round(len) << "\n";

    return 0;
}