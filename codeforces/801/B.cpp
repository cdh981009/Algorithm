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
        ll n, ans;
        cin >> n;
        vl arr(n);
        FOR(i, 0, n) cin >> arr[i];

        bool mike = false;

        if (n % 2) // odd
            mike = true;
        else {
            int mm = INF;
            int mj = INF;
            int mi, ji;
            FOR(i, 0, n) {
                ll x = arr[i];
                if (i % 2 == 0) {
                    if (x < mm) {
                        mm = x;
                        mi = i;
                    }
                } else {
                    if (x < mj) {
                        mj = x;
                        ji = i;
                    }
                }
            }
            if (mm < mj) {
                mike = false;
            } else if (mm > mj) {
                mike = true;
            } else {
                mike = (ji < mi);
            }
        }

        if (mike) cout << "Mike";
        else cout << "Joe";
        cout << '\n';
    }

    return 0;
}