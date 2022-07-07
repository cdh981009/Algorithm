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

constexpr int N = 1010;
constexpr int M = 10007;

ll n, m;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    string s;
    cin >> s;

    int len = 0;
    bool start = false;
    bool prevI = false;
    ll ans = 0;

    auto op = [&]() {
        //cout << len << ' ';
        ans += max(0LL, (len - (2 * n + 1))/2 + 1);
    };

    rep(i, 0, m) {
        if (s[i] == 'I') {
            if (!start) {
                start = true;
                len = 1;
            } else {
                if (prevI) {
                    start = true;
                    op();
                    len = 1;
                } else {
                    len += 2;
                }
            }
        } else {
            if (!prevI) {
                if (start) {
                    start = false;
                    op();
                }
            }
        }
        prevI = (s[i] == 'I');
    }

    op();

    cout << ans << '\n';

    return 0;
}