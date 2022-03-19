#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define fi first
#define se second
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

    int n; cin >> n;
    int mn, mx, tmn, tmx, x;

    tmn = tmx = mn = mx = 0;

    FOR(i, 0, n) {
        cin >> x;
        if (x == 1) {
            mn -= 1;
            mx -= 1;
            mn = min(mn, -1);
            mx = max(mx, -1);
        } else {
            mx += 1;
            mn += 1;
            mn = min(mn, 1);
            mx = max(mx, 1);
        }

        tmn = min(mn, tmn);
        tmx = max(mx, tmx);
    }
    int ans = tmx - tmn + 1;

    cout << ans << '\n';

    return 0;
}