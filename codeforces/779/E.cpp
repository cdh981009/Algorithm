#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 10)
#define fi first
#define se second
#define rep(i, a, b) for (ll i = (a); i < (b); ++i)
#define rep_(i, a, b) for (ll i = (a); i <= (b); ++i)
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (ll i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pii>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 2001;
constexpr int M = 100;

ll n, k, m, ans;
int v[N][N];
pii pos[N * N + 1];
int dp[N * N + 1];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    rep(i, 0, n) {
        rep(j, 0, n) {
            int x;
            cin >> x;
            v[i][j] = x;
            pos[x] = {i, j};
        }
    }

    ll mx1, mx2, mn1, mn2;
    ll si, sj;
    si = pos[n * n].fi;
    sj = pos[n * n].se;
    mx1 = mn1 = si + sj;
    mx2 = mn2 = si - sj;
    dp[n * n] = true;

    for (int i = n * n - 1; i >= 1; --i) {
        int x = pos[i].fi;
        int y = pos[i].se;
        ll t1 = x + y;
        ll t2 = x - y;

        if (abs(t1 - mx1) <= k &&
            abs(t1 - mn1) <= k &&
            abs(t2 - mx2) <= k &&
            abs(t2 - mn2) <= k) {
            dp[i] = true;
            mx1 = max(mx1, t1);
            mx2 = max(mx2, t2);
            mn1 = min(mn1, t1);
            mn2 = min(mn2, t2);
        }
    }

    rep(i, 0, n) {
        rep(j, 0, n) {
            if (dp[v[i][j]])
                cout << 'M';
            else
                cout << 'G';
        }
        cout << '\n';
    }

    return 0;
}