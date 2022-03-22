#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
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
using vpii = vector<pii>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 101010;
constexpr int M = 100;

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
        int x, y;
        cin >> x >> y;

        int ans;
        if (x == 0 && y == 0) {
            ans = 0;
        } else {
            bool one = false;
            FOR_(i, 0, 100) {
                if (x * x + y * y == i * i) {
                    one = true;
                    break;
                }
            }
            if (one) ans = 1;
            else ans = 2;
        }
        cout << ans << '\n';
    }

    return 0;
}