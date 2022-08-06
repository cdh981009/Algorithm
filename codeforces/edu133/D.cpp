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

constexpr int N = 201010;
constexpr int M = 998244353;

ll n, m, k, q;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    vector<int> a(n + 1, 0), b(n + 1, 0), ans(n + 1, 0);
    b[0] = 1;

    ll sum = 0;
    while (true) {
        sum += k;
        if (sum > n) break;
        rep_(i, sum, n) {
            a[i] = ((ll)a[i - k] + b[i - k]) % M;
        }
        k++;
        rep_(i, 0, n) {
            ans[i] = ((ll)ans[i] + a[i]) % M;
            b[i] = 0;
        }
        swap(a, b);
    }

    rep_(i, 1, n)
            cout
        << ans[i] << ' ';
    cout << '\n';

    return 0;
}