#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 100;
constexpr int M = 998244353;

map<ll, ll> mp;

ll getDp(ll n) {
    if (n <= 4) return n;
    if (mp.count(n) == 1) return mp[n];

    if (n % 2 == 0) { // even
        ll ret = getDp(n / 2);
        return mp[n] = (ret * ret) % M;
    } else {
        ll ret = getDp(n / 2) * getDp((n + 1) / 2);
        return mp[n] = ret % M;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n; cin >> n;
    cout << getDp(n) << '\n';

    return 0;
}