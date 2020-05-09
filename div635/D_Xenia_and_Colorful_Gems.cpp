#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

long long ans = LONG_LONG_MAX;

inline long long dist(long long x, long long y, long long z) {
    return (x - y) * (x - y) + (y - z) * (y - z) + (z - x) * (z - x);
}

void comb(vector<int>& pick, vector<int>& o1, vector<int>& o2) {
    FOR(i, 0, pick.size()) {
            int m;
            m = pick[i];
            auto it1 = lower_bound(o1.begin(), o1.end(), m);
            auto it2 = lower_bound(o2.begin(), o2.end(), m);
            vector<int> n, o;
            if (it1 != o1.end())
                n.push_back(*it1);
            if (it1 != o1.begin())
                n.push_back(*(it1 - 1));
            if (it2 != o2.end())
                o.push_back(*it2);
            if (it2 != o2.begin())
                o.push_back(*(it2 - 1));
            for (auto j : n)
                for (auto k : o)
                    ans = min<long long>(ans, dist(m, j, k));
        }
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    while (tc--) {
        int x, y, z; cin >> x >> y >> z;
        vector<int> r, g, b;
        FOR(i, 0, x) {
            int n; cin >> n;
            r.push_back(n);
        }
        FOR(i, 0, y) {
            int n; cin >> n;
            g.push_back(n);
        }
        FOR(i, 0, z) {
            int n; cin >> n;
            b.push_back(n);
        }
        sort(r.begin(), r.end());
        sort(g.begin(), g.end());
        sort(b.begin(), b.end());
        ans = LONG_LONG_MAX;
        comb(r, b, g);
        comb(b, r, g);
        comb(g, r, b);
        cout << ans << endl;
    }
    return 0;
}