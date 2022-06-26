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

constexpr int N = 200000;
constexpr int M = 100;

vpii vec;

void solve(int n, int k, int off) {
    if (n == 1) return;

    int t = (n - 1) * 4;
    int nn = n - 2;
    int noff = off + t;

    if (k - t >= nn - 1) { // go round
        solve(nn, k - t, noff);
    } else { // cut in the corner
        int x = nn * nn - 1;
        if (k - 2 <= x) {
            vec.push_back({off + 2, noff + 1});
            solve(nn, k - 2, noff);
        } else if (k - 4 <= x) {
            vec.push_back({off + n + 1, noff + nn});
            solve(nn, k - 4, noff);
        } else if (k - 6 <= x) {
            vec.push_back({off + 2 * n, noff + 2 * nn - 1});
            solve(nn, k - 6, noff);
        } else {
            vec.push_back({off + 3 * n - 1, noff + 3 * nn - 2});
            solve(nn, k - 8, noff);
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    rep_(testcase, 1, tc) {
        cout << "Case #" << testcase << ": ";

        bool p = true;        
        ll n, k;
        cin >> n >> k;
        vec.clear();

        if (k < n - 1 || k % 2) {
            cout << "IMPOSSIBLE" << '\n';
        } else {
            solve(n, k, 0);
            cout << vec.size() << '\n';
            for (auto &[x, y] : vec) {
                if (x + 1 != y)
                    cout << x << ' ' << y << '\n';
            }
        }
    }

    return 0;
}