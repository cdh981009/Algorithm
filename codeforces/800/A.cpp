#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
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
        cin >> n;
        vector<ll> arr(n);
        FOR(i, 0, n)
        cin >> arr[i];

        bool pos = true;

        ll i, x;
        i = x = 0;
        bool z = false;
        while (i < n) {
            if (i == 0) {
                x = arr[0];
            } else {
                x = arr[i] + x;
            }

            if (z && arr[i] != 0) {
                pos = false;
                break;
            }

            if (x < 0) {
                pos = false;
                break;
            } else if (x == 0) {
                z = true;
            }

            if (i == n - 1) {
                if (x == 0)
                    pos = true;
                else
                    pos = false;
            }
            i++;
        }
        printYN(pos);
    }

    return 0;
}