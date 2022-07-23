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

constexpr int N = 110;
constexpr int M = 8e6 + 10;
constexpr int B = 4e6;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    ll ans = 0;
    vector<pair<int, int>> vec;
    rep(i, 0, n) {
        int x, y;
        cin >> x >> y;
        vec.push_back({y, x});
    }
    sort(vec.rbegin(), vec.rend());
    rep(i, 0, k) {
        ans += vec[i].second;
    }
    rep(i, k, n) {
        swap(vec[i].first, vec[i].second);
    }
    sort(vec.rbegin(), vec.rbegin() + n - k);
    rep(i, 0, m) {
        ans += vec[k + i].first;
    }
    cout << ans << '\n';
    return 0;
}