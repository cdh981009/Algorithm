#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define fi first
#define se second
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (ll i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pii>;

constexpr int N = 2e5 + 10;
constexpr int M = 998244353;

ll fac[N];
ll invFac[N];

struct Seg {
    int n;
    vl a, a2;

    Seg(int sz) {
        n = 1;
        while (n <= sz) n *= 2;
        a.resize(2 * n);
        a2.resize(2 * n, 1);
    }

    void update(int x, int v) {
        x += n;
        a[x] += v;
        a2[x] = invFac[a[x]];
        x /= 2;
        while (x > 0) {
            a[x] = a[2 * x] + a[2 * x + 1];
            a2[x] = (a2[2 * x] * a2[2 * x + 1]) % M;
            x /= 2;
        }
    }

    // sum query
    ll sumq(int s, int e) {
        s += n;
        e += n;
        ll sum = 0;

        while (s <= e) {
            if (s % 2 == 1) {
                sum += a[s++];
            }
            if (e % 2 == 0) {
                sum += a[e--];
            }
            s /= 2;
            e /= 2;
        }

        return sum;
    }

    ll invFacq(int s, int e) {
        s += n;
        e += n;
        ll sum = 1;

        while (s <= e) {
            if (s % 2 == 1) {
                sum *= a2[s++];
                sum %= M;
            }
            if (e % 2 == 0) {
                sum *= a2[e--];
                sum %= M;
            }
            s /= 2;
            e /= 2;
        }

        return sum;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fac[0] = 1;
    fac[1] = 1;
    invFac[0] = 1;
    invFac[1] = 1;
    FOR(i, 2, N) {
        fac[i] = fac[i - 1] * i % M;
        invFac[i] = (M - M / i) % M * invFac[M % i] % M;
    }
    FOR(i, 2, N) {
        invFac[i] = invFac[i - 1] * invFac[i] % M;
    }

    int n, m;
    cin >> n >> m;
    vi s1(n), s2(m);
    FOR(i, 0, n) cin >> s1[i];
    FOR(i, 0, m) cin >> s2[i];

    ll ans = 0;
    Seg seg(2e5 + 1);

    FOR(i, 0, n) {
        seg.update(s1[i], 1);
    }

    bool prefix = true;
    FOR(i, 0, n) {
        if (i < m) {
            int c = s2[i];

            ll small = seg.sumq(0, c - 1);
            ll same = seg.sumq(c, c);
            ll all = seg.sumq(0, 2e5);

            if (small > 0) {
                // put smaller one, already lexicographically small
                // put other ones freely
                ans += small * fac[all - 1] % M * seg.invFacq(0, 2e5) % M;
                ans %= M;
            }

            if (same > 0) {
                seg.update(c, -1);
            } else {  // doomed
                prefix = false;
                break;
            }
        } else {
            break;
        }
    }

    if (n < m && prefix) ans = (ans + 1) % M;


    cout << ans << '\n';
    return 0;
}