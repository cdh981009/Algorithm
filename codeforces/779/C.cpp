#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 10)
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep_(i, a, b) for (int i = (a); i <= (b); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pii>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 101010;
constexpr int M = 100;

ll n, m, ans;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        vl c(n);
        int pos1 = -1;
        ll mx = -1;
        rep(i, 0, n) {
            cin >> c[i];
            if (c[i] == 1) {
                if (pos1 == -1)
                    pos1 = i;
                else
                    pos1 = -2;
            }
            mx = max(c[i], mx);
        }

        bool pos = false;

        if (pos1 >= 0 && mx <= n) {
            pos = true;
            if (n >= 2) {
                rep(i, 0, n) {
                    if (c[i] == 1 && c[(i + 1) % n] != 2) pos = false;
                    if (c[(i + 1) % n] - c[i] >= 2) pos = false;
                }
            }
        }

        cout << (pos ? "Yes" : "No") << '\n';
    }

    return 0;
}