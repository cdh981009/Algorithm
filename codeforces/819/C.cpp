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

constexpr int N = 51;
constexpr int M = 100;

ll n, m, k, q, ans;
ll a[N];
string str;

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
        cin >> n;
        cin >> str;

        int cnt = 0;
        vector<bool> lvl(n + 1, false);

        ans = 0;

        rep(i, 0, 2 * n) {
            if (str[i] == '(') {
                if (!lvl[cnt]) {
                    lvl[cnt] = true;
                    ans++;
                }
                cnt++;
            } else {
                lvl[cnt] = false;
                cnt--;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}