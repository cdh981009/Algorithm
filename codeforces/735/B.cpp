#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 101010;
int n, k;
ll ans;
int arr[N];

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
        cin >> n >> k;
        FOR_(i, 1, n) {
            cin >> arr[i];
        }

        ans = -1e11;
        FOR_(i, max(1, n - 2 * k), n) {
            FOR_(j, i + 1, n) {
                ans = max(ans, (ll)i * j - (ll)k * (arr[i] | arr[j]));
            }
        }

        cout << ans << '\n';
    }
    return 0;
}