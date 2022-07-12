#include <bits/stdc++.h>

using namespace std;

#define INF ((int)(1e9 + 7))
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

    int dp1[3] = {0, 0, 0};
    int dp2[3] = {0, 0, 0};

    int arr[3], aux1[3], aux2[3];
    int n;
    cin >> n;
    rep(i, 0, n) {
        rep(j, 0, 3) {
            cin >> arr[j];
        }
        if (i != 0) {
            swap(aux1, dp1);
            swap(aux2, dp2);
            rep(j, 0, 3) {
                dp1[j] = -1;
                dp2[j] = INF;
                rep_(k, -1, 1) {
                    if (k + j >= 0 && k + j < 3) {
                        dp1[j] = max(dp1[j], aux1[k + j] + arr[j]);
                        dp2[j] = min(dp2[j], aux2[k + j] + arr[j]);
                    }
                }
            }
        } else {
            rep(j, 0, 3)
                dp1[j] = dp2[j] = arr[j];
        }
    }

    sort(dp1, dp1 + 3);
    sort(dp2, dp2 + 3);

    cout << dp1[2] << ' ' << dp2[0] << '\n';

    return 0;
}