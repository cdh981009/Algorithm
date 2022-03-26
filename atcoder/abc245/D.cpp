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
constexpr int M = 100;

ll n, m, ans;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    vi a(n + 1), c(n + m + 1), b(m + 1);
    rep_(i, 0, n) cin >> a[i];
    rep_(i, 0, n + m) cin >> c[i];

    for (int i = n + m; i >= n; --i) {
        ll base = 0;
        for (int j = m; j + n != i; --j) {
            base += b[j] * (i - j >= 0 ? a[i - j] : 0);
        }
        b[i - n] = (c[i] - base) / a[n];
    }

    rep_(i, 0, m) cout << b[i] << ' ';
    cout << '\n';

    return 0;
}