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

set<ll> s;
vector<ll> vec;

void getS(int ind, ll sum, ll x) {
    if (ind == vec.size()) {
        s.insert(sum);
        return;
    } else {
        getS(ind + 1, sum + x * vec[ind], 1);
        getS(ind + 1, sum + x * vec[ind], x * 10LL);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        ll n;
        cin >> n;
        ll sum = 0;
        vec.clear();

        bool _1or0 = true;
        while (n > 0) {
            ll x = n % 10LL;
            sum += x;
            vec.push_back(x);
            n /= 10;

            if (x != 1 && x != 0) _1or0 = false;
        }

        if (_1or0) {
            cout << "Hello, BOJ 2023!\n";
        } else {
            s.clear();
            getS(0, 0, 1);

            int ans = 0;
            ll m = 1;

            auto pow = [](ll a, ll x) {
                ll base = a;
                ll ret = 1;
                while (x) {
                    if (x % 2 == 1) {
                        ret *= base;
                    }
                    base *= base;
                    x /= 2;
                }

                return ret;
            };

            while (true) {
                ll sum = 0;
                for (auto x : vec) {
                    sum += pow(x, m);
                }
                if (s.count(sum) > 0) ans++;
                if (sum > *s.rbegin()) break;
                m++;
            }
            
            cout << ans << '\n';
        }
    }

    return 0;
}