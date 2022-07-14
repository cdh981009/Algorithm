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

constexpr int N = 50;
constexpr int M = 8e6 + 10;
constexpr int B = 4e6;

ll n, s;
vll vec;
ll ans = 0;

map<int, int> solve(int s, int e) {
    map<int, int> mp;
    rep(i, 0, 1 << (e - s)) {
        int sm = 0;
        rep(j, s, e) {
            if ((i >> (j - s)) & 1) {
                sm += vec[j];
            }
        }
        mp[sm]++;
    }

    return mp;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> s;
    vec = vll(n);
    
    rep(i, 0, n) cin >> vec[i];
    auto m1 = solve(0, n / 2);
    auto m2 = solve(n / 2, n);

    for (const auto &[k, v] : m1) {
        if (m2.count(s - k)) {
            ans += (ll)m2[s - k] * v;
        }
    }

    cout << ans - (s == 0) << '\n';

    return 0;
}