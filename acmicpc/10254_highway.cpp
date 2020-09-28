// 10254: highway
// https://www.acmicpc.net/problem/10254
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

// convexHull의 점이 ccw로 들어있어야 한다
pair<const Vector2&, const Vector2&> rotatingCalipers(const vector<Vector2>& convexHull, int r) {
    // looping
    int s = convexHull.size();

    int left = 0;
    int right = r;
    int a = left;
    int b = right;

    int maxA = a;
    int maxB = b;
    long long maxDist = sqrDist(convexHull[a], convexHull[b]);

    while (a != right || b != left) {
        // 다음 캘리퍼스의 후보 두개
        Vector2 caliA = convexHull[(a + 1) % s] - convexHull[a];
        Vector2 caliB = convexHull[(b + 1) % s] - convexHull[b];

        // 각도 비교 대신 ccw를 할 수 있다
        if (a == right) {
            b = (b + 1) % s;
        } else if (b == left) {
            a = (a + 1) % s;
        } else if (cross(caliA, caliB) < 0) { // thetaA < thetaB
            a = (a + 1) % s;
        } else {
            b = (b + 1) % s;
        }

        if (sqrDist(convexHull[a], convexHull[b]) > maxDist) {
            maxDist = sqrDist(convexHull[a], convexHull[b]);
            maxA = a;
            maxB = b;
        }
    }

    return {convexHull[maxA], convexHull[maxB]};
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, x, y;
        vector<Vector2> points;

        cin >> n;
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

        int right = lowerStack.size() - 1;
        vector<Vector2>& convexHull = lowerStack;
        FOR(i, 1, upperStack.size() - 1) {
            convexHull.push_back(upperStack[upperStack.size() - 1 - i]);
        }

        auto res = rotatingCalipers(convexHull, right);

        cout << res.first.x << " " << res.first.y << " "
             << res.second.x << " " << res.second.y << "\n";
    }
    return 0;
}