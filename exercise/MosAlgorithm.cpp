#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pii>;

constexpr int N = 101010;
constexpr int M = 100;

struct Query {
    int l, r, i;

    bool operator< (const Query &o) {
        return this->l < o.l;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n;
    vi a(n);
    FOR(i, 0, n) cin >> a[i];
    
    int sz = sqrt(n);
    vector<vector<Query>> qs(sz + 2);

    cin >> q;
    FOR(i, 0, q) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        qs[r / sz].push_back({l, r, i});
    }

    vector<int> cnt(n + 1, 0);
    vector<int> ans(q);

    int cl, cr;
    cl = cr = 0;
    cnt[a[0]]++;
    int pr = 0;

    auto add = [&](int ind) {
        cnt[a[ind]]++;
        if (cnt[a[ind]] % 2 == 0) pr++;
    };

    auto del = [&](int ind) {
        cnt[a[ind]]--;
        if (cnt[a[ind]] % 2 == 1) pr--;
    };

    FOR(i, 0, qs.size()) {
        auto v = qs[i];
        sort(v.begin(), v.end());
        for (const auto &[l, r, ind] : v) {
            while (cr < r) add(++cr);
            while (cr > r) del(cr--);

            while (cl < l) del(cl++);
            while (cl > l) add(--cl);

            ans[ind] = pr;
        }
    }

    FOR(i, 0, q) cout << ans[i] << '\n';
    
    return 0;
}