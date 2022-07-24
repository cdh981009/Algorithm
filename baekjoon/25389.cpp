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

constexpr int N = 501010;
constexpr int M = 8e6 + 10;
constexpr int B = 4e6;

int n, k;
int arr[N];

struct Seg {
    int n;
    vector<int> vec;
    vector<int> lazy;
    static const int def = 0;

    Seg(int _n, int _def = def) {
        n = 1;
        while (n < _n) n *= 2;
        vec.resize(2 * n, _def);
        lazy.resize(2 * n, _def);
    }

    void prop(int s, int e, int i) {
        if (lazy[i] == 0) return;
        vec[i] += lazy[i];

        if (s != e) {
            lazy[2 * i] += lazy[i];
            lazy[2 * i + 1] += lazy[i];
        }

        lazy[i] = 0;
    }

    // add update
    void update(int node, int nl, int nr, int l, int r, int val) {
        prop(nl, nr, node);

        if (nr < l || nl > r) return;

        if (l <= nl && nr <= r) {
            lazy[node] = val;
            prop(nl, nr, node);
            return;
        }

        int m = (nl + nr) / 2;
        update(2 * node, nl, m, l, r, val);
        update(2 * node + 1, m + 1, nr, l, r, val);
        vec[node] = max(vec[2 * node], vec[2 * node + 1]);
    }

    void update(int l, int r, int val) {
        update(1, 0, n - 1, l, r, val);
    }

    // max query
    int query(int node, int nl, int nr, int l, int r) {
        prop(nl, nr, node);

        if (nr < l || nl > r) return 0;

        if (l <= nl && nr <= r) {
            return vec[node];
        }

        int m = (nl + nr) / 2;
        int res1 = query(2 * node, nl, m, l, r);
        int res2 = query(2 * node + 1, m + 1, nr, l, r);
        return max(res1, res2);
    }

    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    rep(i, 0, n) cin >> arr[i];

    vector<int> lastOccur(k + 1, n);

    Seg seg(n + 1);

    // dp[n] = 0
    // dp[i] = max( f(i, j - 1) + dp[j] )
    // for from j = i + (k + 1) / 2 to n
    // f(i, j) = distinct int except 0 in range (i, j)
    // answer = dp[0]

    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        int x = arr[i];
        if (x != 0) {
            int y = lastOccur[x] - 1;
            seg.update(i + 1, y + 1, 1);

            lastOccur[x] = i;
        }

        int start = min(n, i + (k + 1) / 2);
        int dp = seg.query(start, n);
        // cout << dp << '\n';

        if (i == 0) ans = dp;
        seg.update(i, i, dp);
    }

    cout << ans << '\n';

    return 0;
}