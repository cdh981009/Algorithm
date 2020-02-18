#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define FOR_(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))
#define x first
#define y second

int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int points; cin >> points;
    vector<pair<int, int>> polygon;
    FOR(i, 0, points) {
        int x, y; cin >> x >> y;
        polygon.push_back({x, y});
    }

    if (points % 2) {
        cout << "No\n";
        return 0;
    }

    pair<int, int>& pivot1 = polygon[0];
    decltype(pivot1) pivot2 = polygon[points / 2];
    FOR(i, 0, points / 2) {
        if (pivot1.x - polygon[i].x != - pivot2.x + polygon[i + points / 2].x ||
                pivot1.y - polygon[i].y != - pivot2.y + polygon[i + points / 2].y) {
            cout << "No\n";
            return 0;
        }
    }

    // TODO, determine convex hull 
    cout << "Yes\n";
    return 0;
}