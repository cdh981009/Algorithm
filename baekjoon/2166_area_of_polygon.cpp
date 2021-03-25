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

    auto op = [](const p& l, const p& r) -> long long { return l.x*r.y - r.x*l.y; };
    int n; cin >> n;
    vector<p> polygon;
    FOR(i, 0, n) {
        int x, y; cin >> x >> y;
        polygon.push_back({x, y});
    }
    polygon.push_back(polygon.front());
    double ans = 0;
    FOR(i, 0, n) {
        ans += op(polygon[i], polygon[i+1]);
    }
    ans = abs(ans/2);
    cout << setprecision(1) << fixed << ans << "\n";

    return 0;
}