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

constexpr int N = 601010;
constexpr int M = 1e9 + 7;

int n, m, k, q;

ll fac[N];
ll invf[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fac[0] = fac[1] = 1;
    rep(i, 2, N) fac[i] = fac[i - 1] * i % M;

    invf[0] = invf[1] = 1;
    rep(i, 2, N) invf[i] = ((-M / i + M) % M) * invf[M % i] % M;
    rep(i, 2, N) invf[i] = invf[i - 1] * invf[i] % M;

    string str;
    cin >> str;
    vll vec;
    vec.push_back(0);
    ll ans = 1;

    auto catalan = [&](ll x) {
        return fac[2 * x] * invf[x] % M * invf[x + 1] % M;
    };

    rep(i, 0, str.size()) {
        if (str[i] >= 'a' && str[i] <= 'z') continue;
        if (str[i] == '?') {
            vec.push_back(0);
        } else {
            auto x = vec.back();
            vec.pop_back();
            vec.back()++;
            ans = ans * catalan(x) % M;
        }
    }
    ans = ans * catalan(vec.back()) % M;

    cout << ans << '\n';

    return 0;
}