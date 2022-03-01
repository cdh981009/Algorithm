#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

constexpr int N = 100;
constexpr int M = 998244353;

struct Seg {
    int n;
    vector<int> a;
    
    Seg(int sz) {
        n = 1;
        while (n <= sz) n *= 2;
        a.resize(2 * n);
    }

    void update(int x) {
        x += n;
        a[x] = 1;
        x /= 2;
        while (x > 0) {
            a[x] = a[2 * x] + a[2 * x + 1];
            x /= 2;
        }
    }

    int query(int s, int e) {
        s += n;
        e += n;
        int cnt = 0;

        while (s <= e) {
            if (s % 2 == 1) {
                cnt += a[s++];
            }
            if (e % 2 == 0) {
                cnt += a[e--];
            }
            s /= 2;
            e /= 2;
        }

        return cnt;
    }
};

ll cnt(vi& a) {
    ll ret = 0;
    int n = a.size();
    Seg seg(n);

    FOR(i, 0, n) {
        ret += seg.query(a[i], n - 1);
        seg.update(a[i]);
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

    int n;
    vector<int> a, b;
    cin >> n;
    a = vi(n);
    b = vi(n);

    FOR(i, 0, n) {
        int x; cin >> x;
        a[--x] = i;
    }

    FOR(i, 0, n) {
        int x; cin >> x;
        b[--x] = i;
    }

    // counting inversion
    vi aux(n);
    ll acnt, bcnt;
    acnt = cnt(a);
    bcnt = cnt(b);

    bool pos = true;
    if (acnt % 2 != bcnt % 2) pos = false;

    cout << (pos ? "Possible" : "Impossible") << '\n';

    return 0;
}