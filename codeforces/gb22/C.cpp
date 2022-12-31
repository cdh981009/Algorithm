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

constexpr int N = 100;
constexpr int M = 10100;

ll n, m, k, q, ans;
ll a[N];
ll fac[M];
vector<int> primes;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    rep(i, 0, M) {
        fac[i] = i;
    }

    for (int i = 2; i * i < M; ++i) {
        for (int j = i * i; j < M; j += i) {
            if (fac[j] == j) fac[j] = i;
        }
    }

    for (int i = 2; i < M; ++i)
        if (fac[i] == i) primes.push_back(i);

    ll tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        map<ll, set<ll>> pcnt;
        bool pos = true;

        rep(i, 0, n) {
            ll x;
            cin >> x;
            a[i] = x;
        }

        rep(i, 0, n) {
            rep(j, i + 1, n) {
                ll x = abs(a[i] - a[j]);

                if (x == 0) {
                    pos = false;
                    break;
                } else if (x == 1)
                    continue;

                ll r = a[i] % x;

                rep(l, 0, primes.size()) {
                    if (x % primes[l] == 0) {
                        ll f = primes[l];

                        ll rr = (f - (r % f)) % f;
                        pcnt[f].insert(rr);

                        if (pcnt[f].size() == f) {
                            pos = false;
                            break;
                        }
                    }
                }
            }
            if (!pos) break;
        }

        printYN(pos);
    }

    return 0;
}