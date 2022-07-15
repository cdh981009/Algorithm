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

constexpr int N = 201010;
constexpr int M = 100;

ll n, ans;
string s, t;

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
        cin >> s >> t;
        vi v1, v2;
        int c1, c2;
        c1 = c2 = 0;
        rep(i, 0, n - 1) {
            if (s[i] != s[i+1]) v1.push_back(1), c1++;
            else v1.push_back(0);
            if (t[i] != t[i+1]) v2.push_back(1), c2++;
            else v2.push_back(0);
        }
        if (s[0] != t[0] || s[n-1] != t[n-1] || c1 != c2) ans = -1;
        else {
            ans = 0;
            int j = 0;
            rep(i, 0, n - 1) {
                if (v1[i] == 1) {
                    while (v2[j] == 0) j++;
                    ans += abs(i - j);
                    j++;
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}