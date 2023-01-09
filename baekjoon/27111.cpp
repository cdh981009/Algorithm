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

constexpr int N = 5010;
constexpr int M = 100;

ll n, m, k, q, ans;
int number[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    
    cin >> n;
    map<int, int> mp;
    rep(i, 0, n) {
        int a, b;
        cin >> a >> b;
        if (mp.count(a) == 0) {
            mp[a] = 0;
        }

        if (mp[a] == b) {
            ans++;
        }
        mp[a] = b;
    }

    for (auto &[k, v] : mp) {
        if (v == 1) ans++;
    }

    cout << ans << '\n';

    return 0;
}