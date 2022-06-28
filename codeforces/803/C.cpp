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

constexpr int N = 201010;
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
        cin >> n;
        rep(i, 0, n) cin >> arr[i];

        sort(arr, arr + n);

        bool pos = true;

        if (n == 3) {
            ll sum = arr[0] + arr[1] + arr[2];

            pos = false;

            rep(i, 0, 3) {
                if (sum == arr[i]) pos = true;
            }
        } else if (n == 4) {
            ll sum = 0;
            rep(i, 0, 4) sum += arr[i];

            rep(i, 0, 4) {
                ll x = sum - arr[i];
                pos = false;
                rep(j, 0, 4) {
                    if (x == arr[j]) pos = true;
                }
                if (!pos) break;
            }
        } else {
            rep(i, 1, n - 1) {
                if (arr[i] != 0) {
                    pos = false;
                    break;
                }
            }

            if (pos) {
                if (arr[0] != 0 && arr[n - 1] != 0) {
                    pos = (arr[0] == -arr[n - 1]);
                } else if (arr[0] != 0) {
                    pos = (arr[n - 1] == 0);
                } else if (arr[n - 1] != 0) {
                    pos = (arr[0] == 0);
                }
            }
        }

        printYN(pos);
    }

    return 0;
}