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

constexpr int N = 201010;
constexpr int M = 100;

int n, m, k, q, ans;
int arr[N];

struct Bit {
    vector<ll> arr;
    ll n;

    void init(int sz) {
        n = sz + 1;
        arr = vll(n);
    }

    void update(int idx, ll v) {
        ll i = idx + 1;
        while (i < n) {
            arr[i] += v;
            i += (i & -i);
        }
    }

    ll query(int idx) {
        ll i = idx + 1;
        ll res = 0;
        while (i >= 1) {
            res += arr[i];
            i -= (i & -i);
        }
        return res;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> q;

    vll points;
    set<ll> integers;

    struct Q {
        ll t, a, b, x;
    };

    vector<Q> queries;

    rep(i, 0, q) {
        ll a, b, t, p;
        cin >> t >> a;

        if (t == 1) {
            cin >> b;

            if (a != 0) {
                if (b % a == 0) {  // integer point
                    p = -b / a;
                } else {
                    auto sign = [](ll x) {
                        return x > 0 ? 1 : (x == 0) ? 0
                                                    : -1;
                    };

                    ll aa = abs(a), bb = abs(b);

                    if (sign(a) != sign(b)) {
                        p = (bb + aa - 1) / aa;
                    } else {
                        p = -b / a;
                    }
                }

                points.push_back(p);
            }
        } else {
            points.push_back(a);
        }

        queries.push_back({t, a, b, p});
    }

    // init bit
    sort(points.begin(), points.end());
    points.erase(unique(points.begin(), points.end()), points.end());

    Bit bit;
    bit.init(points.size());

    ll s = 1;
    for (auto [t, a, b, p] : queries) {
        if (t == 1) {
            if (a == 0) {
                if (b == 0) {
                    s = 0;
                } else {
                    s *= b > 0 ? 1 : -1;
                }
            } else {
                if (b % a == 0) 
                    integers.insert(p);
                    
                s *= a > 0 ? -1 : 1;

                ll idx = lower_bound(points.begin(), points.end(), p) - points.begin();
                bit.update(idx, 1);
            }

        } else {  // t == 2
            ll res;

            if (s == 0 || integers.count(a)) {
                cout << "0\n";
                continue;
            }

            ll idx = lower_bound(points.begin(), points.end(), a) - points.begin();

            res = (bit.query(idx) % 2 == 1) ? -1 : 1;
            res *= s;

            if (res > 0) {
                cout << '+';
            } else {
                cout << '-';
            }
            cout << '\n';
        }
    }

    return 0;
}