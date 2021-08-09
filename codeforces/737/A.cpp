#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 101010;

int n;
double ans;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        ans = 0;
        cin >> n;
        int mx = -INF;
        double sum = 0;
        FOR(i, 0, n) {
            int x; cin >> x;
            if (x > mx) {
                mx = x;
            }
            sum += x;
        }
        sum -= mx;
        ans = sum / (n - 1);
        ans += mx;

        cout << setprecision(10) << fixed << ans << '\n';
    }
    return 0;
}