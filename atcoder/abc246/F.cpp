#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
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
using vpii = vector<pii>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 101010;
constexpr int M = 998244353;

ll n, l, x;
vector<string> strs;

ll modpow(ll a, ll x) {
    ll ret = 1;
    ll base = a;
    while (x) {
        if (x % 2) ret = ret * base % M;
        base = base * base % M;
        x /= 2;
    }
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> l;
    rep(i, 0, n) {
        string str; cin >> str;
        strs.push_back(str);
    }

    ll ans = 0;

    rep(i, 1, (1 << n)) {

        int bc = 0;
        vector<int> cnt(26, 0);
        rep(j, 0, n) {
            if (i & (1<<j)) {
                bc++;
                for (auto &c : strs[j]) {
                    cnt[c - 'a']++;
                }
            }
        }

        int x = 0;
        rep(j, 0, 26) {
            if (cnt[j] == bc) x++;
        }
        
        ll res = modpow(x, l);

        if (bc % 2) { // odd -> +
            ans = (ans + res) % M;
        } else {
            ans = (ans - res + M) % M;
        }
    }

    cout << ans << '\n';

    return 0;
}