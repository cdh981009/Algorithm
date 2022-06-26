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

constexpr int N = 100;
constexpr int M = 100;

ll e, w, ans;
vector<vi> req;
map<pair<vi, int>, int> mp;

ll brute(const vector<int>& pv, int ind) {
    if (ind == e) {
        return pv.size();
    } else {
        if (mp.count({pv, ind})) return mp[{pv, ind}];

        vector<int> nv;
        ll mn = INT64_MAX;

        FOR(i, 0, w) {
            FOR(j, 0, req[ind][i]) {
                nv.push_back(i);
            }
        }

        auto getDiff = [&]() {
            int i = 0;
            while (i < pv.size() && i < nv.size()) {
                if (pv[i] != nv[i]) break;
                i++;
            }
            return max((ll)pv.size() - i, 0LL) + max((ll)nv.size() - i, 0LL);
        };

        do {
            ll res = getDiff();

            mn = min(mn, res + brute(nv, ind + 1));
        } while (next_permutation(nv.begin(), nv.end()));

        mp[{pv, ind}] = mn;

        return mn;
    }
}

ll solve() {
    ll ans = 0;
    vi matching(w, 100);
    ll prvrs = 0;
    FOR(i, 0, e) {
        vi& ref = req[i];
        // match with prev
        bool perfect = true;
        FOR(j, 0, w) {
            if (matching[j] > ref[j]) {
                perfect = false;
            }
            matching[j] = min(matching[j], ref[j]);
        }
        ll ms = 0;
        FOR(j, 0, w) {
            ms += matching[j];
        }

        ll rs = 0;
        FOR(j, 0, w) {
            rs += ref[j];
        }

        // if (perfect) {
        //     FOR(j, 0, w)
        //         matching[j] = ref[j];
        // }

        if (i == 0) {
            ans += rs;
        } else {
            ans += prvrs - ms;
            ans += rs - ms;
        }

        if (i == e - 1) {
            ans += rs;
        }

        prvrs = rs;
    }

    return ans;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    rep_(testcase, 1, tc) {
        cout << "Case #" << testcase << ": ";

        cin >> e >> w;
        req = vector<vi>(e, vi(w, 0));
        FOR(i, 0, e) {
            FOR(j, 0, w) {
                int x; cin >> x;
                req[i][j] = x;
            }
        }


        ll ans = solve();
        reverse(req.begin(), req.end());
        ans = min(solve(), ans);

        vi v;
        mp.clear();
        ll bAns = ans;
        bAns = brute(v, 0); // comment here

        if (ans != bAns) {
            cout << ans << ' ' << bAns << '\n';
        }

        cout << ans << '\n';
    }


    return 0;
}