// 9240: 로버트 후드
// https://www.acmicpc.net/problem/9240
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

struct Vector2D {
    int x, y;

    Vector2D(int x, int y) : x(x), y(y) {}
};

Vector2D operator+(const Vector2D& l, const Vector2D& r) {
    return Vector2D(l.x + r.x, l.y + r.y);
}

Vector2D operator-(const Vector2D& l, const Vector2D& r) {
    return Vector2D(l.x - r.x, l.y - r.y);
}

long long crossProduct(const Vector2D& l, const Vector2D& r) {
    return (long long)l.x * r.y - l.y * r.x;
}

int abs(const Vector2D& v) {
    return v.x * v.x + v.y * v.y;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, x, y;
    vector<Vector2D> points;

    cin >> n;
    points.reserve(n);
    FOR(i, 0, n) {
        cin >> x >> y;
        points.push_back(Vector2D(x, y));
    }
    sort(points.begin(), points.end(), [](const Vector2D& l, const Vector2D& r) {
        return (l.x != r.x) ? l.x < r.x : l.y < r.y;
    });

    auto ccw = [](const Vector2D& a, const Vector2D& b, const Vector2D& c) {
        return crossProduct(b - a, c - b);
    };

    // getting convex hull
    vector<int> upperStack, lowerStack;
    FOR(i, 0, n) {
        while (upperStack.size() >= 2 &&
                ccw(
                        points[upperStack[upperStack.size() - 2]],
                        points[upperStack[upperStack.size() - 1]],
                        points[i]) >= 0) {
            upperStack.pop_back();
        }
        upperStack.push_back(i);

        while (lowerStack.size() >= 2 &&
                ccw(
                        points[lowerStack[lowerStack.size() - 2]],
                        points[lowerStack[lowerStack.size() - 1]],
                        points[i]) <= 0) {
            lowerStack.pop_back();
        }
        lowerStack.push_back(i);
    }
    
    vector<int>& convexHull = lowerStack;
    FOR(i, 1, upperStack.size() - 1) {
        convexHull.push_back(upperStack[upperStack.size() - 1 - i]);
    }

    // calculate furthest points
    int mDist = 0;
    FOR(i, 0, convexHull.size()) {
        FOR(j, i + 1, convexHull.size()) {
            mDist = max(mDist, abs(points[convexHull[i]] - points[convexHull[j]]));
        }
    }

    cout << setprecision(10) << fixed << sqrt(mDist) << "\n";
    return 0;
}