#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 101010;
constexpr int M = 998244353;

int n, m, k, q;
vector<int> x, y;

ll modpow(ll a, ll x) {
    ll ret = 1;
    ll base = a;
    while (x) {
        if (x % 2) {
            ret *= base;
            ret %= M;
        }
        base *= base;
        base %= M;
        x /= 2;
    }
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n >> m >> k >> q;
        x = vector<int> (q);
        y = vector<int> (q);
        FOR(i, 0, q) {
            cin >> x[i] >> y[i];
            x[i]--;
            y[i]--;
        }

        vector<bool> xv(n, 0);
        vector<bool> yv(m, 0);
        int cntx = 0, cnty = 0;
        bool fx, fy;
        fx = fy = false;

        int cnt = 0;
        for (int i = q - 1; i >= 0; --i) {
            int cx = x[i];
            int cy = y[i];

            bool nx, ny;
            nx = ny = false;

            if (xv[cx] || fy) nx = true;
            if (yv[cy] || fx) ny = true;

            if (!xv[cx]) cntx++;
            if (cntx == n) fx = true; 
            if (!yv[cy]) cnty++;
            if (cnty == m) fy = true;

            xv[cx] = true;
            yv[cy] = true;

            if (nx && ny) continue;
            cnt++;
        }

        cout << modpow(k, cnt) << '\n';
    }

    return 0;
}