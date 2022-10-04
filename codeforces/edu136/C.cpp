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

constexpr int N = 70;
constexpr int M = 998244353;

ll n, m, k, q, ans;
ll comb[N][N];

bool mem[N];
struct Dp {
    ll x, y, z;
};
Dp dp[N];

ll getComb(int n, int r) {
    if (r > n) return 0;
    if (r >= n / 2) r = n - r;
    if (r == 0) return 1;

    if (comb[n][r] != -1) return comb[n][r];

    return comb[n][r] = (getComb(n - 1, r - 1) + getComb(n - 1, r)) % M;
}

void getDp(int n) {
    if (n == 2) {
        dp[2] = {1, 0, 1};
        return;
    }

    if (mem[n]) return;
    mem[n] = true;

    dp[n] = {getComb(n - 1, n/2 - 1), getComb(n - 2, n / 2 - 2), 0};
    getDp(n - 2);

    dp[n].x += dp[n - 2].y;
    dp[n].x %= M;
    dp[n].y += dp[n - 2].x;
    dp[n].y %= M;
    dp[n].z += dp[n - 2].z;
    return;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(comb, -1, sizeof(comb));

    ll tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        
        getDp(n);
        auto &[x, y, z] = dp[n];

        cout << x << ' ' << y << ' ' << z << '\n';
    }

    return 0;
}