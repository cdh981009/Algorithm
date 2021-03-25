// 3679: 단순 다각형
// https://www.acmicpc.net/problem/3679
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

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, x, y;
        cin >> n;
        vector<pair<Vector2, int>> points;
        points.reserve(n);
        FOR(i, 0, n) {
            cin >> x >> y;
            points.push_back({Vector2(x, y), i});
        }

        sort(points.begin(), points.end(), [](const pair<Vector2, int>& l, const pair<Vector2, int>& r) {
            return (l.first.x != r.first.x) ? l.first.x < r.first.x : l.first.y < r.first.y;
        });

        vector<int> upperStack;
        vector<bool> used(n, false);

        auto ccw = [](const Vector2& l, const Vector2& m, const Vector2& r) {
            return cross(m - l, r - m);
        };

        FOR(i, 0, points.size()) {
            while (upperStack.size() >= 2 &&
                    ccw(
                            points[upperStack[upperStack.size() - 2]].first,
                            points[upperStack[upperStack.size() - 1]].first,
                            points[i].first) > 0) { // ccw == 0 일때도 넘어간다, i.e. 일직선이어도 윗 껍질에 넣는다
                upperStack.pop_back();
            }
            upperStack.push_back(i);
        }

        FOR(i, 0, upperStack.size()) {
            cout << points[upperStack[i]].second << " ";
            used[upperStack[i]] = true;
        }

        FOR(i, 0, points.size()) {
            int ind = points.size() - 1 - i;
            if (used[ind])
                continue;
            cout << points[ind].second << " ";
        }

        cout << "\n";

        
    }
    return 0;
}