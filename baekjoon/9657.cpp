#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 7)
#define fi first
#define se second
#define rep(i, a, b) for (ll i = (a); i < (b); ++i)
#define rep_(i, a, b) for (ll i = (a); i <= (b); ++i)
#define repr_(i, a, b) for (ll i = (a); i >= (b); --i)
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (ll i = (a); i <= (b); ++i)
#define printYN(pos) cout << (pos ? "YES" : "NO") << '\n'
#define printPOS(pos) cout << (pos ? "POSSIBLE" : "IMPOSSIBLE") << '\n'

using ll = long long;
using pii = pair<ll, ll>;
using pll = pair<ll, ll>;
using vi = vector<ll>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using mii = map<ll, ll>;
using mll = map<ll, ll>;

constexpr ll N = 1000;

ll n, m;
ll ans;
vector<int> dp;

// false if I lose whatever I do
// true  if I can win if played optimally
//     = if my act can reach false state
bool getDp(int x) {
    if (x == 0) return false;
    auto& ref = dp[x];
    if (ref != -1) return ref;

    ref = false;
    if (getDp(x - 1) == false) ref = true;
    if (x - 3 >= 0 && getDp(x - 3) == false) ref = true;
    if (x - 4 >= 0 && getDp(x - 4) == false) ref = true;

    return ref;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    dp = vector<int>(n+1, -1);
    auto res = getDp(n);

    cout << (res ? "SK" : "CY") << '\n';

    return 0;
}