#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 1e4;

int ans;
int arr[31];
int n, l;

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
        cin >> n >> l;
        memset(arr, 0, sizeof(arr));
        
        ll sum = 0;
        FOR(i, 0, n) {
            int x; cin >> x;
            FOR(j, 0, l) {
                arr[j] += (x % 2);
                x /= 2;
            }
        }
        
        int x = 1;
        ans = 0;
        FOR(j, 0, l) {
            if (arr[j] > n / 2) ans += x;
            x *= 2;
        }

        cout << ans << '\n';
    }
    return 0;
}