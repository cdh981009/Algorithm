// 7869: Circular Area
// https://www.acmicpc.net/problem/7869
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

const double pi = 3.14159265358979323846264338327950288;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    double x1, x2, y1, y2, r1, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    double x, y, z, a1, a2, d;
    d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

    double area = 0;
    if (d >= r1 + r2) {
        area = 0;
    } else if (d + min(r1, r2) <= max(r1, r2)) {
        area = pi * min(r1, r2) * min(r1, r2);
    } else {
        x = (d * d + r1 * r1 - r2 * r2) / (2 * d);
        y = d - x;
        z = sqrt(r1 * r1 - x * x);
        a1 = acos(x / r1);
        a2 = acos(y / r2);
        area = a1 * r1 * r1 + a2 * r2 * r2 - d * z;
    }

    cout << fixed << setprecision(3) << area << '\n';

    return 0;
}