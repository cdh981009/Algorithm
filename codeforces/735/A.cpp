#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 301010;
int n;
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
        ans = 1;
        cin >> n;
        FOR(i, 0, n) {
            cin >> arr[i];
        }

        FOR(i, 1, n) {
            ans = max(ans, (ll) arr[i - 1] * arr[i]);
        }

        cout << ans << '\n';
    }
    return 0;
}