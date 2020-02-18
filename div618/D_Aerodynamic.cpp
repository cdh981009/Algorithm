#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define FOR_(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))
#define x first
#define y second
#define ll long long

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
    //cout << "dot reflectiviy passed\n";

    FOR(i, 0, points) {
        pair<int, int>& curr = polygon[i];
        pair<int, int>& prev = (i == 0) ? polygon.back() : polygon[i - 1];
        pair<int, int>& next = (i == points - 1) ? polygon.front() : polygon[i + 1];
        pair<int, int> vector1 = {prev.x - curr.x, prev.y - curr.y};
        pair<int, int> vector2 = {next.x - curr.x, next.y - curr.y};
        bool convex = (ll) vector1.x * vector2.y < (ll) vector1.y * vector2.x;
        if (!convex) {
            cout << "No\n";
            return 0;
        }
    }
    // cout << "convex hull reflectiviy passed\n";

    cout << "Yes\n";
    return 0;
}