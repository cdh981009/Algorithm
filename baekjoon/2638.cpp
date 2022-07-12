#include <bits/stdc++.h>

using namespace std;

#define INF ((int)(1e9 + 7))
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

constexpr int N = 100;

int n, m;
bool c[N][N];
bool visited[N][N];
int cnt[N][N];
int ans = 0;

void fill(int x, int y) {
    if (c[x][y]) {
        cnt[x][y]++;
        return;
    }
    
    visited[x][y] = true;
    rep(i, 0, 4) {
        int nx = x + "1012"[i] - '1';
        int ny = y + "0121"[i] - '1';
        bool inBound = (nx >= 0 && nx < n && ny >= 0 && ny < m);

        if (!inBound || visited[nx][ny]) continue;
        fill(nx, ny);
    }
}

bool solve() {
    bool b = false;

    rep(i, 0, n) rep(j, 0, m) cnt[i][j] = visited[i][j] = 0;

    fill(0, 0);

    rep(i, 0, n)
        rep(j, 0, m) if (c[i][j] && cnt[i][j] >= 2) {
        c[i][j] = 0,
        b = true;
    }

    return b;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    rep(i, 0, n)
            rep(j, 0, m)
                cin >>
        c[i][j];

    while (solve()) {
        ans++;
    }

    cout << ans << '\n';

    return 0;
}