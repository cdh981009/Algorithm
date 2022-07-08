#include <bits/stdc++.h>

using namespace std;

#define INF (1e9+7)
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

constexpr int N = 110;
constexpr int M = 100;

ll n, m, k, q, ans;
ll arr[N];

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
        ll n; cin >> n;
        set<int> s;
        rep_(i, 1, n) s.insert(i);
        int d = 2;
        vector<int> vec;
        while (!s.empty()) {
            int x = *s.begin();
            vec.push_back(x);
            s.erase(x);
            while (true) {
                if (s.count(2 * x)) {
                    x = 2 * x;
                    vec.push_back(x);
                    s.erase(x);
                } else break;
            }
        }

        cout << d << '\n';
        for (auto &x : vec) cout << x << ' ';
        cout << '\n';
    }

    return 0;
}