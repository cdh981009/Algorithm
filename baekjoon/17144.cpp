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

ll n, m, t;
int arr[N][N];
int aux[N][N];
int u, d;

bool bound(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void op1() {
    memset(aux, 0, sizeof(aux));
    rep(i, 0, n) rep(j, 0, m) {
        if (arr[i][j] == -1) {
            aux[i][j] = -1;
        } else {
            int cnt = 0;
            rep(k, 0, 4) {
                int x = i + "1012"[k] - '1';
                int y = j + "2101"[k] - '1';
                if (!bound(x,y) || arr[x][y] == -1) continue;
                cnt++;
                aux[x][y] += arr[i][j] / 5;
            }
            aux[i][j] += arr[i][j] - cnt * (arr[i][j] / 5);
        }
    }
    swap(aux, arr);
}

void op2() {
    memset(aux, 0, sizeof(aux));

    rep(i, 0, n) rep(j, 0, m) {
        if (i == 0 || i == u || i == d || i == n - 1 ||
            j == 0 || j == m - 1) continue;
        aux[i][j] = arr[i][j];
    }

    rep(i, 0, m - 1)
        aux[0][i] = arr[0][i+1];
    rep(i, 0, u)
        aux[i][m-1] = arr[i+1][m-1];
    rep(i, 2, m)
        aux[u][i] = arr[u][i-1];
    rep_(i, 1, u-1)
        aux[i][0] = arr[i-1][0];

    rep(i, 0, m - 1)
        aux[n-1][i] = arr[n-1][i+1];
    rep(i, d + 1, n - 1)
        aux[i][0] = arr[i+1][0];
    rep(i, 2, m)
        aux[d][i] = arr[d][i-1];
    rep_(i, d+1, n-1)
        aux[i][m-1] = arr[i-1][m-1];

    aux[u][0] = aux[d][0] = -1;

    swap(aux, arr);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> t;
    rep(i, 0, n) rep(j, 0, m) {
        cin >> arr[i][j];
        if (arr[i][j] == -1 && u == 0) {
            u = i;
            d = i + 1;
        }
    }
    rep(i, 0, t) {
        op1();
        op2();
    }

    ll ans = 2;
    rep(i, 0, n) rep(j, 0, m) ans += arr[i][j];

    cout << ans << '\n';

    return 0;
}