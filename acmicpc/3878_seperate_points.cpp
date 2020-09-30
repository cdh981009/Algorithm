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

bool operator!=(const Vector2& l, const Vector2& r) {
    return !(l == r);
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

long long dot(const Vector2& l, const Vector2& r) {
    return (long long)l.x * r.x + (long long)l.y * r.y;
}

long long absSqr(const Vector2& v) {
    return (long long)v.x * v.x + (long long)v.y * v.y;
}

vector<Vector2> getConvexHull(vector<Vector2>& points) {
    sort(points.begin(), points.end(), [](const Vector2& l, const Vector2& r) {
        return (l.x != r.x) ? l.x < r.x : l.y < r.y;
    });

    vector<Vector2> upperStack, lowerStack;

    auto ccw = [](const Vector2& l, const Vector2& m, const Vector2& r) {
        return cross(m - l, r - m);
    };

    FOR(i, 0, points.size()) {
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

    return convexHull;
}

bool lineCross(const Vector2& p1, const Vector2& p2, const Vector2& q1, const Vector2& q2) {
    auto ccw = [](const Vector2& l, const Vector2& r) {
        auto res = cross(l, r);
        return res > 0 ? 1 : res == 0 ? 0 : -1;
    };

    auto a = ccw(p2 - p1, q1 - p1) * ccw(p2 - p1, q2 - p1);
    auto b = ccw(q2 - q1, p1 - q1) * ccw(q2 - q1, p2 - q1);

    bool cross;
    if (p1 == q1 ||
            p1 == q2 ||
            p2 == q1 ||
            p2 == q2) { // 한 꼭짓점에서 만난다
        cross = true;
    } else if (a == 0 && b == 0) { // 일직선상에 있다
        vector<const Vector2*> aux = {&p1, &p2, &q1, &q2};

        sort(aux.begin(), aux.end(), [](const Vector2* l, const Vector2* r) {
            return (l->x != r->x) ? l->x < r->x : l->y < r->y;
        });

        if (*aux[0] == p1 || *aux[0] == p2)
            cross = (*aux[1] != p1 && *aux[1] != p2);
        else
            cross = (*aux[1] != q1 && *aux[1] != q2);
    } else { // 교차한다
        cross = (a <= 0 && b <= 0);
    }

    return cross;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, m, x, y;
        cin >> n >> m;
        vector<Vector2> p1, p2;
        p1.reserve(n);
        p2.reserve(m);

        FOR(i, 0, n) {
            cin >> x >> y;
            p1.push_back(Vector2(x, y));
        }

        FOR(i, 0, m) {
            cin >> x >> y;
            p2.push_back(Vector2(x, y));
        }

        vector<Vector2> hull1 = getConvexHull(p1);
        vector<Vector2> hull2 = getConvexHull(p2);

        bool possible = true;

        // 1. cross test
        FOR(i, 0, hull1.size()) {
            auto& p1 = hull1[i];
            auto& p2 = hull1[(i + 1) % hull1.size()];

            bool cross = false;
            FOR(j, 0, hull2.size()) {
                auto& q1 = hull2[j];
                auto& q2 = hull2[(j + 1) % hull2.size()];

                cross = lineCross(p1, p2, q1, q2);
                if (cross)
                    break;
            }
            if (cross) {
                possible = false;
                break;
            }
        }

        // 2. contain test
        if (possible) {
            auto test = [](const vector<Vector2>& hull1, const vector<Vector2>& hull2) {
                bool contain = false;

                FOR(i, 0, hull1.size()) {
                    auto& p = hull1[0];
                    int match = 0;
                    
                    FOR(j, 0, hull2.size()) {
                        auto& q1 = hull2[j];
                        auto& q2 = hull2[(j + 1) % hull2.size()];

                        int ccw = cross(q2 - q1, p - q1);
                        if (ccw > 0 || (ccw == 0 && dot(q2 - q1, p - q1) > 0)) {
                            match++;
                        }
                    }

                    if (match == hull2.size()) {
                        contain = true;
                        break;
                    }
                }

                return contain;
            };

            possible = !test(hull1, hull2) && !test(hull2, hull1); 
        }

        cout << (possible ? "YES" : "NO") << "\n";
    }
    return 0;
}