#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pii>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 201010;
constexpr int M = 100;

mii v[N];
pii ans[N];
bool visited[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    FOR(i, 0, n) {
        int x, y;
        cin >> x >> y;
        v[x][y] = i;
    }

    auto exist = [&](int x, int y) {
        return x >= 0 && v[x].count(y);
    };

    queue<pair<pii, pii>> q;

    FOR(x, 0, N) {
        for (auto &[y, ind] : v[x]) {
            FOR(i, 0, 4) {
                int nx = "1012"[i] - '1' + x;
                int ny = "0121"[i] - '1' + y;

                if (!exist(nx, ny)) {
                    q.push({{nx, ny}, {nx, ny}});
                }
            }
        }
    }

    while (!q.empty()) {
        auto pp = q.front();
        q.pop();
        auto curr = pp.fi;
        auto from = pp.se;

        int x = curr.fi;
        int y = curr.se;

        if (exist(x, y)) {
            ans[v[x][y]] = from;
        }
        FOR(i, 0, 4) {
            int nx = "1012"[i] - '1' + x;
            int ny = "0121"[i] - '1' + y;

            if (exist(nx, ny) && !visited[v[nx][ny]]) {
                visited[v[nx][ny]] = true;
                q.push({{nx, ny}, from});
            }
        }
    }

    FOR(i, 0, n)
        cout << ans[i].fi << ' ' << ans[i].se << '\n';

    return 0;
}