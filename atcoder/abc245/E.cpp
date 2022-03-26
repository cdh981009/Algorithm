#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 10)
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
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pii>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 101010;
constexpr int M = 100;

ll n, m, ans;
vpii cho, box;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    cho.resize(n);
    box.resize(m);

    rep(i, 0, n) cin >> cho[i].fi;
    rep(i, 0, n) cin >> cho[i].se;
    rep(i, 0, m) cin >> box[i].fi;
    rep(i, 0, m) cin >> box[i].se;

    sort(cho.rbegin(), cho.rend());
    sort(box.rbegin(), box.rend());

    multiset<int> s;

    bool pos = true;
    int i = 0;

    for (auto &[x, y] : cho) {
        while (i < m && box[i].fi >= x) {
            s.insert(box[i].se);
            i++;
        }
        
        if (s.empty()) {
            pos = false;
            break;
        }

        auto it = s.lower_bound(y);
        if (it == s.end()) {
            pos = false;
            break;
        }

        s.erase(it);
    }

    cout << (pos ? "Yes" : "No") << '\n';

    return 0;
}