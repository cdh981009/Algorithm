#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 7)
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep_(i, a, b) for (int i = (a); i <= (b); ++i)
#define repr_(i, a, b) for (int i = (a); i >= (b); --i)
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

constexpr int N = 300;
constexpr int M = 100;

ll n, m, k, q, ans;
ll a[N], b[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        vector<vector<int>> mat(n, vector<int>(n, 0));

        int num = 1;
        rep(i, 0, n) {
            rep(j, 0, n) {
                mat[i][i % 2 == 0 ? j : (n - 1 - j)] =
                    num % 2 == 1 ? (num + 1) / 2 : (n * n - (num - 1) / 2);
                num++;
            }
        }

        rep(i, 0, n) {
            rep(j, 0, n) {
                cout << mat[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}