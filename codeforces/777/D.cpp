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
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 101010;
constexpr int M = 100;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        ll x, d; cin >> x >> d;

        bool pos;

        auto is_prime = [](int x) {
            for (ll i = 2; i * i <= x; ++i) {
                if (x % i == 0) {
                    return false;
                }
            }
            return true;
        };

        auto fac = [](int x) {
            vector<int> ps;

            for (ll i = 2; i * i <= x; ++i) {
                if (x % i == 0) ps.push_back(i);

                while (x % i == 0) {
                    x /= i;
                }
            }
            if (x > 1 && (ps.empty() || ps.back() != x))
                ps.push_back(x);

            return ps;
        };

        if ((x / d) % d != 0) {
            pos = false;
        } else {
            int cnt = 0;
            while (x % d == 0) {
                x /= d;
                cnt++;
            }
            if (!is_prime(x)) { // x not prime
                pos = true;
            } else {
                if (is_prime(d)) { // d prime
                    pos = false;
                } else{
                    auto v = fac(d);
                    if (cnt >= 4) {
                        pos = true;
                    } else if (cnt == 2) {
                        pos = false;
                    } else { // cnt == 3
                        pos = false;
                        for (auto &ps : v) {
                            if ((x * ps) % d != 0) {
                                pos = true;
                                break;
                            }
                        }
                    }
                }
            }
        }


        cout << (pos ? "YES" : "NO") << '\n';
    }

    return 0;
}