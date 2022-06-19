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
    //  freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll tc;
    cin >> tc;
    while (tc--) {
        ll n;
        string str, ans;
        cin >> n >> str;
        string y;
        y.resize(n + 1);

        bool sm = true;
        FOR(i, 0, n) {
            int x = str[i] -'0';
            if (x > 1) {
                sm = false;
                break;
            }
            if (x == 0) {
                break;
            }
        }

        if (sm) { // 9999..
            ans = str;
            FOR(i, 0, n) {
                ans[i] = (9 - ans[i] + '0') + '0';
            }
        } else { // 1111..
            int b = 0;
            FOR(i, 0, n) {
                int x = 1;
                
                if (b) {
                    x = 0;
                }
                
                if (str[n - i - 1] > x + '0') {
                    b = true;
                    x += 10;
                } else {
                    b = false;
                }

                ans.push_back(x - (str[n - i - 1] - '0') + '0');
            }

            reverse(ans.begin(), ans.end());

        }

        cout << ans << '\n';
    }

    return 0;
}