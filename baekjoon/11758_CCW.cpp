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

    int x[3], y[3];
    FOR(i, 0, 3)
        cin >> x[i] >> y[i];
    p line[2];
    FOR(i, 0, 2)
        line[i] = {x[i + 1] - x[i], y[i + 1] - y[i]};
    auto op = [](const p& l, const p& r) -> long long { return l.x*r.y - r.x*l.y; };
    int res = op(line[0], line[1]);
    cout << (0 < res) - (res < 0) << "\n";
    return 0;
}