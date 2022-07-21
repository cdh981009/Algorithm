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

ll n, m, k, q, ans;
ll arr[N];

// counting (sum) seg
struct Seg {
    int n;
    vector<int> a;
    
    Seg(int sz) {
        n = 1;
        while (n <= sz) n *= 2;
        a.resize(2 * n, INF);
    }

    Seg(vi& v) {
        n = 1;
        int sz = v.size();
        while (n <= sz) n *= 2;
        a.resize(2 * n);

        int def = INF; /* default value */
        for (int i = 0; i < n; ++i) {
            a[i + n] = (i < sz ? v[i] : def);
        }
        for (int i = n - 1; i >= 1; --i) {
            a[i] = min(a[2 * i], a[2 * i + 1]);
        }
    }

    // set update
    void update(int x, int v) {
        x += n;
        a[x] = v;
        x /= 2;
        while (x > 0) {
            a[x] = min(a[2 * x], a[2 * x + 1]);
            x /= 2;
        }
    }

    // min query
    int query(int s, int e) {
        s += n;
        e += n;
        int res = INF;

        while (s <= e) {
            if (s % 2 == 1) {
                res = min(res, a[s++]);
            }
            if (e % 2 == 0) {
                res = min(res, a[e--]);
            }
            s /= 2;
            e /= 2;
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

    cin >> n >> m;
    Seg seg(m);
    rep(i, 0, m) {
        cin >> arr[i];
        arr[i] = n - arr[i];
        seg.update(i, arr[i]);
    }

    cin >> q;
    rep(i, 0, q) {
        ll xs, ys, xf, yf, k;
        cin >> xs >> ys >> xf >> yf >> k;
        ll dx = abs(xs - xf);
        ll dy = abs(ys - yf);
        bool pos = true;
        if ((dx % k) || (dy % k))
            pos = false;
        else {
            ys--, yf--;
            xs = n - xs + 1;
            xf = n - xf + 1;
            if (ys > yf) swap(ys, yf);
            if (ys + 1 <= yf - 1) {
                int mnx = seg.query(ys + 1, yf - 1);
                if (xs > mnx) {
                    ll xx = xs - mnx;
                    ll xxx = ((ll)xx + (k - 1)) / k * k;
                    if (xs - xxx <= 0) pos = false;
                }
            }        
        }

        printYN(pos);
    }

    return 0;
}