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

constexpr int N = 50;
constexpr int M = 1e9 + 7;

int arr[N][N];
bool vst[N][N];
int n, m;
vpii c;
int ans = INF;

int bfs() {
    memset(vst, 0, sizeof(vst));
    queue<pair<int, pii>> q;
    for (auto [x, y] : c) {
        if (arr[x][y] != 2) continue;
        vst[x][y] = true;
        q.push({0, {x, y}});
    }

    int res = 0;
    while (!q.empty()) {
        auto [d, p] = q.front();
        auto [cx, cy] = p;
        q.pop();
        if (arr[cx][cy] == 1) res += d;
        rep(i, 0, 4) {
            int nx = cx + "1012"[i] - '1';
            int ny = cy + "2101"[i] - '1';
            bool bound = nx >= 0 && nx < n && ny >= 0 && ny < n;
            if (!bound || vst[nx][ny]) continue;
            vst[nx][ny] = true;
            q.push({d + 1, {nx, ny}});
        }
    }

    return res;
}

void solve(int x, int i) {
    if (x == c.size() - m) {
        ans = min(ans, bfs());
        return;
    }
    rep(j, i, c.size()) {
        auto [cx, cy] = c[j];
        if (arr[cx][cy] == 2) {
            arr[cx][cy] = 0;
            solve(x + 1, j + 1);
            arr[cx][cy] = 2;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    rep(i, 0, n) rep(j, 0, n) {
        cin >> arr[i][j];
        if (arr[i][j] == 2) {
            c.push_back({i, j});
        }
    }
    solve(0, 0);

    cout << ans << '\n';

    return 0;
}