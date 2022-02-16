#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)
#define int long long

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 100;
constexpr int M = 100;

struct Bit {
    int n;
    vector<int> v;

    Bit(int _n, int x) {
        v = vector<int> (_n + 1, x);
        n = v.size();
    }

    // add update
    void update(int i, int x) {
        i += 1;
        while (i < n) {
            v[i] += x;
            i += (i & -i);
        }
    }

    // [0...x] sum query
    int query(int i) {
        int ret = 0;
        i += 1;
        while (i > 0) {
            ret += v[i];
            i -= (i & -i);
        }
        return ret;
    }
};

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<ll> col(n + 1, 0);
    Bit bit(n, 0);
    set<pii> ranges;
    ranges.insert({0, 1});
    ranges.insert({n, 1});

    FOR(i, 0, q) {
        string str;
        cin >> str;
        if (str == "Color") {
            int l, r, c; cin >> l >> r >> c;
            l--, r--;
            auto it = ranges.upper_bound({l, INF});
            --it; // l 보다 작거나 같은 지점

            vector<pii> aux = {{l, c}};
            while (true) {
                if (r < it->first) break;
                int ul, ur, uc;
                uc = it->second;

                if (it->first < l) {
                    aux.push_back({it->first, uc});
                    ul = l;
                } else {
                    ul = it->first;
                }

                if (r + 1 < next(it)->first) {
                    aux.push_back({r + 1, uc});
                    ur = r;
                } else {
                    ur = next(it)->first - 1;
                }

                bit.update(ul, col[uc]);
                bit.update(ur + 1, -col[uc]);
                bit.update(ul, -col[c]);
                bit.update(ur + 1, +col[c]);

                it = ranges.erase(it);
            }


            for (auto &p : aux) {
                ranges.insert(p);
            }

        } else if (str == "Add") {
            int c, x; cin >> c >> x;
            col[c] += x;

        } else { // Query
            int i; cin >> i;
            i--;
            auto it = ranges.upper_bound({i, INF});
            it--; // l 보다 작거나 같은 지점

            int c = it->second;
            //cout << col[c] << ' ' << bit.query(i) << '\n';
            cout << bit.query(i) + col[c] << '\n';
        }
    }
    return 0;
}