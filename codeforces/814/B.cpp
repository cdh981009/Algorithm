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

constexpr int N = 101010;
constexpr int M = 100;

ll n, m, k, q, ans;
ll a[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> k;
        vector<pii> v;
        bool p = false;

        if (k % 2) {
            p = true;
            for (int i = 1; i <= n; i += 2) {
                v.push_back({i, i + 1});
            }
        } else {
            vector<int> u1, u2;
            vector<int> notuse;
            for (int i = 1; i <= n; ++i) {
                if (u1.size() + u2.size() == n / 2) {
                    notuse.push_back(i);
                    continue;
                } 
                if (i % 4 == 0 || (i + k) % 4 == 0) {
                    if (i % 4 == 0)
                        u1.push_back(i);
                    else
                        u2.push_back(i);
                } else {
                    notuse.push_back(i);
                }
            }
            if (u1.size() + u2.size() == n / 2) {
                p = true;
                for (auto x : u1) {
                    v.push_back({notuse.back(), x});
                    notuse.pop_back();
                }
                for (auto x: u2) {
                    v.push_back({x, notuse.back()});
                    notuse.pop_back();
                }
            }
        }

        if (p) {
            cout << "YES\n";
            rep(i, 0, n / 2)
                    cout
                << v[i].first << ' ' << v[i].second << '\n';

        } else {
            cout << "NO\n";
        }
    }

    return 0;
}