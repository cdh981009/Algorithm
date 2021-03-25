// 20149: 선분 교차 3
// https://www.acmicpc.net/problem/20149
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

struct Vec2 {
    long long x, y;
};

long long cross(const Vec2& l, const Vec2& r) {
    return l.x * r.y - r.x * l.y;
}

Vec2 operator+(const Vec2& l, const Vec2& r) {
    return {l.x + r.x, l.y + r.y};
}

Vec2 operator-(const Vec2& l, const Vec2& r) {
    return {l.x - r.x, l.y - r.y};
}

bool operator==(const Vec2& l, const Vec2& r) {
    return l.x == r.x && l.y == r.y;
}

bool operator!=(const Vec2& l, const Vec2& r) {
    return !(l == r);
}

bool operator<(const Vec2& l, const Vec2& r) {
    return l.x == r.x ? l.y < r.y : l.x < r.x;
}

int ccw(const Vec2& a, const Vec2& b, const Vec2& c) {
    long long ret = cross(b - a, c - a);
    return ret > 0 ? 1 : (ret == 0 ? 0 : -1);
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    Vec2 p1, p2, p3, p4;

    cin >> p1.x >> p1.y >>
            p2.x >> p2.y >>
            p3.x >> p3.y >>
            p4.x >> p4.y;

    int a1 = ccw(p1, p2, p3);
    int a2 = ccw(p1, p2, p4);
    int b1 = ccw(p3, p4, p1);
    int b2 = ccw(p3, p4, p2);

    double vx;
    double vy;
    bool point = false;
    bool ans = false;;

    if (a1 == 0 && a2 == 0 && b1 == 0 && b2 == 0) { // 일직선상에 존재
        Vec2 aux[4] = {p1, p2, p3, p4};
        sort(aux, aux + 4);

        // 선이 서로 만나는지 확인
        if (aux[0] == p1 || aux[0] == p2) {
            ans = (aux[1] == p3 || aux[1] == p4);
        } else {
            ans = (aux[1] == p1 || aux[1] == p2);
        }

        if (ans && (aux[1] == aux[2])) { // 한점만 만나는지
            point = true;
            vx = aux[1].x;
            vy = aux[1].y;
        }
    } else { // 일직선상에 존재하지 않는다
        ans = (a1 * a2 <= 0 && b1 * b2 <= 0); // 두선이 겹친다
        if (ans) {
            point = true;
            Vec2 s = p4 - p3;
            Vec2 r = p2 - p1;
            double t = (double)cross(s, p3 - p1) / cross(s, r);

            vx = t * r.x + p1.x;
            vy = t * r.y + p1.y;
        }
    }

    cout << ans << '\n';
    if (point) {
        cout << fixed << setprecision(13) << vx << ' ' << vy << '\n';
    }

    return 0;
}