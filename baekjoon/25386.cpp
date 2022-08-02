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

constexpr ll N = 301010;

ll n, m;
ll ans;
ll a[N], b[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ans = -1;
    bool pos = true;

    cin >> m >> n;

    rep(i, 0, n) {
        cin >> a[i];
        a[i]--;
    }

    set<int> bs;
    rep(i, 0, n) {
        cin >> b[i];
        b[i]--;
        if (bs.count(b[i])) {
            pos = false;
        }
        bs.insert(b[i]);
    }

    if (n == m) {
        rep(i, 0, n) {
            if (a[i] != b[i]) {
                pos = false;
                break;
            }
        }
    }

    if (pos) {
        deque<int> deq;
        vector<pair<int, int>> vec;
        rep(i, 0, n) {
            deq.push_back(a[i]);
            vec.push_back({b[i], a[i]});
        }
        sort(deq.begin(), deq.end());
        sort(vec.begin(), vec.end());
        while (deq.front() != vec.front().second) {
            deq.push_back(deq.front());
            deq.pop_front();
        }
        rep(i, 0, n) {
            if (deq[i] != vec[i].second) {
                pos = false;
                break;
            }
        }

        if (pos) {
            ans = 0;
            rep(i, 0, n) {
                ans += (a[i] - b[i] + m) % m;
                vec.push_back({b[i] + m, a[i] + m});
            }
            sort(vec.begin(), vec.end());
            set<int> s, s2;
            rep(i, 0, vec.size()) {
                while (vec[i].second < vec[i].first) vec[i].second += m;
                int e = vec[i].second;

                auto it = s.upper_bound(e);

                if (it != s.end()) {
                    int ss = vec[i].first % m;
                    if (!s2.count(ss)) {
                        ans += m;
                        s2.insert(ss);
                    }
                }

                s.insert(e);
            }
        }
    }


    cout << ans << '\n';

    return 0;
}