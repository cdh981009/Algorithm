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

constexpr int N = 8;
constexpr int M = 1e9 + 7;

int arr[N][N];
bool vst[N][N];
int n, m;
int w;
int ans;

int dfs(int x, int y) {
    vst[x][y] = true;
    ll res = 1;
    rep(i, 0, 4) {
        int nx = x + "1012"[i] - '1';
        int ny = y + "2101"[i] - '1';
        bool bound = nx >= 0 && nx < n && ny >= 0 && ny < m;
        if (!bound) continue;
        if (!vst[nx][ny] && arr[nx][ny] != 1) res += dfs(nx, ny);
    }
    return res;
}

int fill() {
    memset(vst, 0, sizeof(vst));
    int virus = 0;
    rep(i, 0, n) rep(j, 0, m) if (!vst[i][j] && arr[i][j] == 2)
        virus += dfs(i, j);

    return n * m - w - virus;
}

void solve(int x) {
    if (x == 3) {
        ans = max(ans, fill());
        return;
    }
    rep(i, 0, n) {
        rep(j, 0, m) {
            if (arr[i][j] == 0) {
                arr[i][j] = 1;
                solve(x + 1);
                arr[i][j] = 0;
            }
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
    rep(i, 0, n) rep(j, 0, m) {
        cin >> arr[i][j];
        if (arr[i][j] == 1) w++;
    }
    w += 3;
    solve(0);

    cout << ans << '\n';

    return 0;
}