#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 7)
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep_(i, a, b) for (int i = (a); i <= (b); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)
#define printYN(pos) cout << (pos ? "YES" : "NO") << '\n'
#define printPOS(pos) cout << (pos ? "POSSIBLE" : "IMPOSSIBLE") << '\n'

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 21;
constexpr int M = 10007;

ll n, m, ans;
int a[N][N];
bool visited[N][N];
int x, y, s, cnt;

using fish = pair<int, pii>;

bool solve() {
    memset(visited, 0, sizeof(visited));

    vector<fish> f;
    queue<fish> q;

    visited[x][y] = true;
    q.push({0, {x, y}});

    auto inBound = [](int nx, int ny) {
        return nx >= 0 && nx < n && ny >= 0 && ny < n;
    };

    while (!q.empty()) {
        auto [dist, p] = q.front();
        auto [cx, cy] = p;

        q.pop();

        rep(i, 0, 4) {
            int nx = cx + "1012"[i] - '1';
            int ny = cy + "2101"[i] - '1';

            if (!inBound(nx, ny) || visited[nx][ny]) continue;
            if (a[nx][ny] > s) continue;

            q.push({dist + 1, {nx, ny}});
            visited[nx][ny] = true;

            if (a[nx][ny] < s && a[nx][ny] != 0) f.push_back({dist + 1, {nx, ny}});
        }
    }

    sort(f.begin(), f.end());

    if (f.empty()) return false;

    auto [dist, p] = f.front();
    auto [nx, ny] = p;
    x = nx;
    y = ny;
    a[nx][ny] = 0;

    ans += dist;
    cnt ++;
    if (cnt == s) s++, cnt = 0;
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    rep(i, 0, n) {
        rep(j, 0, n) {
            cin >> a[i][j];
            if (a[i][j] == 9) {
                x = i, y = j;
                a[i][j] = 0;
            }
        }
    }

    s = 2;
    cnt = 0;
    while (solve())
        ;

    cout << ans << '\n';

    return 0;
}