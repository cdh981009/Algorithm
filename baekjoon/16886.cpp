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

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    // prefix xor of grundynum
    vll nimber(n + 1, 0);
    int ans = -1;

    rep_(i, 1, n) {
        ll s = 1;
        int j = 2;
        vector<int> ress;
        while (true) {
            s += j;
            if (s > i) break;
            if ((i - s) % j == 0) {
                ll x = (i - s) / j;
                // 1 + x, 2 + x, ... , j + x
                ll res = nimber[j + x] ^ nimber[x];
                ress.push_back(res);

                if (i == n && res == 0 && ans == -1) {
                    ans = j;
                }
            }
            j++;
        }

        sort(ress.begin(), ress.end());
        ress.erase(unique(ress.begin(), ress.end()), ress.end());
        ress.push_back(INF);

        rep(k, 0, ress.size()) {
            if (ress[k] != k) {
                nimber[i] = k ^ nimber[i - 1];
                //cout << i << ' ' << k << '\n';
                break;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}