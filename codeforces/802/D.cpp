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
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pii>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 101010;
constexpr int M = 100;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, q;
    cin >> n;
    vl arr(n);
    vl psum(n);
    FOR(i, 0, n) {
        cin >> arr[i];
        if (i == 0)
            psum[i] = arr[i];
        else
            psum[i] = arr[i] + psum[i-1];
    }

    ll sum = psum[n - 1];
    vl p2t(n);
    ll mt = 0;

    FOR(i, 0, n) {
        if (i > 0) {
            mt = max(mt, (psum[i - 1] + i - 1) / i);
        }
        p2t[i] = max((sum + i) / (i + 1), mt);
    }
    reverse(p2t.begin(), p2t.end());

    cin >> q;
    FOR(i, 0, q) {
        int t; cin >> t;
        auto it = upper_bound(p2t.begin(), p2t.end(), t);
        ll ans = 0;
        if (it == p2t.begin()) {
            ans = -1;
        } else {
            it--;
            ans = p2t.end() - it;
        }
        cout << ans << '\n';
    }

    return 0;
}