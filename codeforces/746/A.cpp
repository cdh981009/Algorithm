#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 1e4;

int ans;
int arr[N];
int n, m;

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
        cin >> n >> m;
        FOR(i, 0, n) {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        int x = arr[n - 1];
        int y = arr[n - 2];
        if (x >= m) {
            ans = 1;
        } else {
            ans = (m - 1) / (x + y);
            m -= ans * (x + y);
            ans *= 2;
            if (m > 0)
                ans++, m -= x;
            if (m > 0)
                ans++, m -= y;
        }
        ans = max(1, ans);
        cout << ans << '\n';
    }
    return 0;
}