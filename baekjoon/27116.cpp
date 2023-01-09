#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 7)
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep_(i, a, b) for (int i = (a); i <= (b); ++i)
#define repr_(i, a, b) for (int i = (a); i >= (b); --i)
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

constexpr int N = 101010;
constexpr int M = 110;

ll n, m, r, k, q, ans;
ll adj[M][M];
ll fuel[M];
ll route[N];
ll psum[N];

void floyd() {
    rep(k, 0, m) {
        rep(i, 0, m) {
            rep(j, 0, m) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif

    cin >> n >> m >> r;

    rep(i, 0, m) {
        rep(j, 0, m) {
            cin >> adj[i][j];
        }
    }

    floyd();

    rep(i, 0, m) {
        cin >> fuel[i];
    }

    route[0] = 0;
    rep_(i, 1, n) {
        cin >> route[i];
        route[i]--;
        psum[i] = psum[i - 1] + adj[route[i - 1]][route[i]];
    }

    bool pos = false;
    ll minLocation = n;
    ll minFuel = INT64_MAX;

    // no help
    rep_(i, 1, n) {
        ll nohelp = psum[n] + fuel[route[i]];

        if (nohelp <= r) {
            minLocation = 0;
            minFuel = min(nohelp, minFuel);
            pos = true;
        }
    }

    if (!pos) {
        rep_(i, 1, n) {  // land on ith
            ll pre = psum[i] + fuel[route[i]];

            // do binary search
            // from i+1, do x routes
            int x = 0;
            int mx = n;

            auto op = [&](int x) {
                int start = i + x + 1;

                if (start > n) {
                    return pre;
                }

                ll suf = psum[n] - psum[start];

                return pre + suf + adj[route[i]][route[start]];
            };

            for (int step = mx; step >= 1; step /= 2) {
                while (x + step <= mx && op(x + step) > r) {
                    x += step;
                }
            }

            x++;
            if (op(x) <= r) {
                pos = true;
                ll f = op(x);  // from i + 1 to i + x + 1
                if (x < minLocation || (x == minLocation && f < minFuel)) {
                    minLocation = x;
                    minFuel = f;
                }
            }
        }
    }

    if (!pos)
        cout << -1 << '\n';
    else {
        cout << minLocation << ' ' << minFuel << '\n';
    }

    return 0;
}