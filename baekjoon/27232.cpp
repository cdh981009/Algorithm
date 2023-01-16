#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 7)
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep_(i, a, b) for (int i = (a); i <= (b); ++i)
#define repr_(i, a, b) for (int i = (a); i >= (b); --i)
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

constexpr int N = 501010;
constexpr int M = 100;

ll n, m, k, q, ans;
ll a[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    rep(i, 0, n) cin >> a[i];


    set<pair<ll, ll>> s;

    ll ans = INT64_MAX;
    
    rep(i, 0, k) {
        s.insert({a[i], i});
    }

    ll res = 0;
    ll prev = -1;
    for (auto &[fi, se] : s) {
        if (prev != -1) {
            res += abs(prev - se);
        }
        prev = se;
    }

    ans = res;

    rep(i, k, n) {
        // erase i - k
        auto it = s.find({a[i - k], i - k});

        auto prv = it;
        auto nxt = it;

        int cnt = 0;
        if (it != s.begin()) {
            prv--;
            res -= abs(prv->se - it->se);
            cnt++;
        }

        if (++nxt != s.end()) {
            res -= abs(nxt->se - it->se);
            cnt++;
        }

        if (cnt == 2) {
            res += abs(prv->se - nxt->se);
        }
        s.erase(it);

        // insert i

        s.insert({a[i], i});

        it = s.find({a[i], i});

        prv = it;
        nxt = it;
        cnt = 0;

        if (it != s.begin()) {
            prv--;
            res += abs(prv->se - it->se);
            cnt++;
        }

        if (++nxt != s.end()) {
            res += abs(nxt->se - it->se);
            cnt++;
        }

        if (cnt == 2) {
            res -= abs(prv->se - nxt->se);
        }

        ans = min(ans, res);

    }

    cout << ans << '\n';

    return 0;
}