#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 100;


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> a(n);
    vector<int> cnt(30, 0);
    ll ans = 0;
    FOR(i, 0, n) {
        int x; cin >> x;
        ans += x;
        a[i] = x;
        FOR(j, 0, 30) {
            if (x & (1 << j)) cnt[j]++;
        }
    }

    for (auto &x : a) {
        ll res = 0;
        FOR(i, 0, 30) {
            if (x & (1 << i)) {
                res += (ll)(n - cnt[i]) * (1 << i);
            } else {
                res += (ll)cnt[i] * (1 << i);
            }
        }
        ans = max(ans, res);
    }

    cout << ans << '\n';

    return 0;
}