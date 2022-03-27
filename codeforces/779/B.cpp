#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 10)
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep_(i, a, b) for (int i = (a); i <= (b); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pii>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 101010;
constexpr int M = 998244353;

ll n, m, ans;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll fac[1010];
    fac[0] = 1;
    rep(i, 1, 1010) fac[i] = fac[i-1]*i%M;

    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        if (n % 2) cout << 0 << '\n';
        else {
            ll e = n / 2;
            e = fac[e];
            e *= e;
            e %= M;
            cout << e << '\n';
        }
    }

    return 0;
}