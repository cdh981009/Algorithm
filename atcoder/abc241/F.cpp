#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define first fi
#define second se
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 101010;

int h, w, n;
int sx, sy, gx, gy;

map<int, vector<int>> ox;
map<int, vector<int>> oy;
set<pii> visited;

struct pos {
    int x, y, dist;
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> h >> w >> n;
    cin >> sx >> sy >> gx >> gy;
    FOR(i, 0, n) {
        int x, y;
        cin >> x >> y;
        ox[x].push_back(y);
        oy[y].push_back(x);
    }

    for (auto &[k, v] : ox) {
        sort(v.begin(), v.end());
    }

    for (auto &[k, v] : oy) {
        sort(v.begin(), v.end());
    }

    queue<pos> q;
    q.push({sx, sy, 0});
    visited.insert({sx, sy});

    int ans = -1;
    while (!q.empty()) {
        auto pos = q.front();
        q.pop();

        if (pos.x == gx && pos.y == gy) {
            ans = pos.dist;
            break;
        } else {
            auto push = [&](int x, int y) {
                if (visited.count({x, y})) return;
                visited.insert({x, y});
                q.push({x, y, pos.dist + 1});
            };

            if (ox.count(pos.x)) {
                auto v = ox[pos.x];
                auto git = lower_bound(v.begin(), v.end(), pos.y);
                auto lit = git - 1;
                if (git != v.end()) {
                    push(pos.x, *git - 1);
                }

                if (lit >= v.begin()) {
                    push(pos.x, *lit + 1);
                }
            }

            if (oy.count(pos.y)) {
                auto v = oy[pos.y];
                auto git = lower_bound(v.begin(), v.end(), pos.x);
                auto lit = git - 1;
                if (git != v.end()) {
                    push(*git - 1, pos.y);
                }

                if (lit >= v.begin()) {
                    push(*lit + 1, pos.y);
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}