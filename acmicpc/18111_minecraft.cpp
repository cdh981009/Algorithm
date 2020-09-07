#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, b; cin >> n >> m >> b;
    vector<vector<int>> ground(n, vector<int>(m));
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            int x; cin >> x;
            ground[i][j] = x;
        }
    }
    int ansTime = INF;
    int ansX = 0;
    FOR_(x, 0, 256) {
        int time = 0;
        int inventory = b;
        FOR(i, 0, n) {
            FOR(j, 0, m) {
                if (ground[i][j] > x) {
                    time += 2 * (ground[i][j] - x);
                } else {
                    time += x - ground[i][j];
                }
                inventory += ground[i][j] - x;
            }
        }
        if (inventory >= 0 && ansTime >= time) {
            ansTime = time;
            ansX = x;
        }
    }
    cout << ansTime << " " << ansX << "\n";
    return 0;
}