#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

struct p {
    long long x, y;
};

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int x[4], y[4];
    FOR(i, 0, 4)
        cin >> x[i] >> y[i];
    p pts[4];
    FOR(i, 0, 4) {
        pts[i] = {x[i], y[i]};
    }

    auto op = [&pts](int a, int b, int c) -> int {
        p l = {pts[b].x - pts[a].x, pts[b].y - pts[a].y};
        p r = {pts[c].x - pts[b].x, pts[c].y - pts[b].y};
        long long res = l.x * r.y - r.x * l.y;
        return (0 < res) - (res < 0);
    };

    cout << (op(0, 1, 2) != op(0, 1, 3) &&
             op(2, 3, 0) != op(2, 3, 1)) << "\n";
    return 0;
}