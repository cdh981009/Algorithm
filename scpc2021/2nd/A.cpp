#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 101010;

ll n;
ll ans;

int main(int argc, char** argv) {
    int T, tc;

    freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    for (tc = 0; tc < T; tc++) {
        cin >> n;
        ans = 0;

        ans = 2 * n - 1;

        FOR(i, 1, n) {
            double x = sqrt((double)n * n - (double)i * i);
            ll y = ceil(x - 1);
            ans += 4 * y + 2;
        }

        cout << "Case #" << tc + 1 << endl;
        cout << ans << endl;
    }

    return 0;
}