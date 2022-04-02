#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define FOR_(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))

int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    FOR_(t, 1, tc) {
        int x, y; cin >> x >> y;
        string route; cin >> route;
        int minTime = 10000;
        if (x == 0 && y == 0)
            minTime = 0;
        for (int i = 0; i < route.size(); ++i) {
            char c = route[i];
            if (c == 'E') {
                x++;
            } else if (c == 'W') {
                x--;
            } else if (c== 'N') {
                y++;
            } else {
                y--;
            }
            int distance = abs(x) + abs(y);
            //cout << "time " << i + 1 << " " << x << " " << y << " " << distance << endl;
            if (i + 1 >= distance)
                minTime = min(minTime, i + 1);
        }
        cout << "Case #" << t << ": ";
        if (minTime == 10000)
            cout << "IMPOSSIBLE\n";
        else 
            cout << minTime << "\n";
    }
    return 0;
}