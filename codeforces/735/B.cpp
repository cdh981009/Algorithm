#include <bits/stdc++.h>

using namespace std;

#define INF 1e12;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 301010;
int n;
int k;
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
        FOR(i, 0, n) {
            cin >> arr[i + 1];
        }

        ans = -INF;
        for (int i = n; i >= 1; --i) {
            int j = i - 1;
            int cnt = 0;
            while (j >= 1 && cnt <= k + 10) {
                cnt++;
                ans = max(ans, (ll)i * j - (ll)k * (arr[i] | arr[j]));
                j--;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}