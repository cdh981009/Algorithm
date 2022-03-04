#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pii>;

constexpr int N = 101010;
constexpr int M = 100;

ll fac[16];

int cnt(ll x) {
    int ret = 0;
    FOR(i, 0, 40) {
        if (x & (1LL << i)) {
            ret++;
        }
    }
    return ret;
}

int solve(ll x, int ind) {
    int ret = 0;
    ret = cnt(x);
    
    for (int i = ind; i >= 0; --i) {
        if (x - fac[i] >= 0) {
            ret = min(ret, 1 + solve(x - fac[i], i - 1));
        }
    }

    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    fac[0] = 1;
    FOR(i, 1, 16) {
        fac[i] = i * fac[i - 1];
    }
    while (tc--) {
        ll n;
        cin >> n;

        cout << solve(n, 15) << '\n';
    }

    return 0;
}