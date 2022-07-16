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
constexpr int M = 8e6 + 10;
constexpr int B = 4e6;

ll n, m;
string arr[N];
bool vst[N][N];
string str;
set<char> s;
int ans;
bool ch;

void dfs(int x, int y) {
    if (vst[x][y]) return;
    if (x < 0 || x >= n || y < 0 || y >= m) return;
    if (arr[x][y] == '*') return;
    if (arr[x][y] >= 'A' && arr[x][y] <= 'Z')
        if (!s.count(arr[x][y])) return;
    if (arr[x][y] >= 'a' && arr[x][y] <= 'z')
        if (!s.count(arr[x][y])) ch = true, s.insert(toupper(arr[x][y]));
    if (arr[x][y] == '$')
        ans++;
    vst[x][y] = true;
    arr[x][y] = '.';

    rep(i, 0, 4) {
        int nx = x + "1012"[i] - '1';
        int ny = y + "2101"[i] - '1';
        dfs(nx, ny);
    }
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        s.clear();

        cin >> n >> m;
        rep(i, 0, n) cin >> arr[i];

        cin >> str;
        if (str != "0")
            rep(i, 0, str.size()) s.insert(toupper(str[i]));

        ans = 0;
        ch = true;
        while (ch) {
            memset(vst, 0, sizeof(vst));
            ch = false;
            rep(i, 0, n) rep(j, 0, m) if ((i == 0 || j == 0 || i == n-1 || j== m-1) && !vst[i][j]) dfs(i, j);
        }

        cout << ans << '\n';
    }
    return 0;
}