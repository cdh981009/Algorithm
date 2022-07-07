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

constexpr int N = 1010101;
constexpr int M = 10007;

ll n, m;
ll dp[N];
bool pos[10];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));
    cin >> n >> m;

    rep(i, 0, 10) pos[i] = true;

    rep(i, 0, m) {
        int x; cin >> x;
        pos[x] = false;
    }

    int ans = abs(n - 100);

    auto op1 = [](int x){
        while (true) {
            int y = x % 10;
            x /= 10;
            if (pos[y] == false) return false;
            if (x == 0) break;
        }
        return true;
    };

    auto op2 = [](int x) {
        return to_string(x).size();
    };

    rep(i, 0, N) {
        if (op1(i))
            ans = min((ll)ans, (ll)op2(i) + abs(n - i));
    }

    cout << ans << '\n';

    return 0;
}