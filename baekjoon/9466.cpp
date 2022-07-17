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

constexpr int N = 101010;
constexpr int M = 8e6 + 10;

ll n, ans;
ll arr[N];
int vst[N];

int dfs(int x) {
    vst[x] = 1;
    auto nxt = arr[x];

    if (vst[nxt] == 1) {
        vst[x] = 2;
        ans--;
        if (nxt != x) {
            return nxt;
        }
    } else if (vst[nxt] == 0) {
        int y = dfs(nxt);
        vst[x] = 2;
        if (y != -1) ans--;

        if (y == x)
            return -1;
        else
            return y;
    } else {
        vst[x] = 2;
    }
    return -1;
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
        cin >> n;
        rep(i, 0, n) {
            cin >> arr[i];
            arr[i]--;
        }
        memset(vst, 0, sizeof(vst));
        ans = n;
        rep(i, 0, n) if (vst[i] == 0) dfs(i);

        cout << ans << '\n';
    }
    return 0;
}