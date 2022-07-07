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

constexpr int N = 110;
constexpr int M = 10007;

ll n;
char a[N][N];
bool visited[N][N];

bool inBound(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int dfs(int x, int y, bool b) {
    visited[x][y] = true;

    auto isSame = [&b](char i, char j) {
        if (b) {
            if (i == 'B') return j == 'B';
            else return j != 'B';
        } else {
            return i == j;
        }
    };

    rep(i, 0, 4) {
        int nx = x + "1012"[i] - '1';
        int ny = y + "0121"[i] - '1';
        if (!inBound(nx, ny) || visited[nx][ny]) continue;
        if (isSame(a[x][y], a[nx][ny]))
            dfs(nx, ny, b);
    }
    return 1;
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
        }
    }

    int h, c;
    h = c = 0;
    rep(i, 0, n) {
        rep(j, 0, n) {
            if (!visited[i][j]) h += dfs(i, j, false);
        }
    }
    memset(visited, false, sizeof(visited));
    rep(i, 0, n) {
        rep(j, 0, n) {
            if (!visited[i][j]) c += dfs(i, j, true);
        }
    }

    cout << h << ' ' << c << '\n';
    return 0;
}