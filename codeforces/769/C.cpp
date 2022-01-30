#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 100;

int ans;
int arr[N];
int a, b;

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
        cin >> a >> b;
        
        int ans = b - a;
        ans = min(ans, 1 + ((a | b) - b));

        int x = a;
        int cnt = 0;
        while (true) {
            if ((x | b) == b) {
                ans = min(ans, cnt + 1);
                break;
            }
            x++;
            cnt++;
        }

        x = b;
        cnt = 0;
        while (true) {
            if ((a | x) == x) {
                ans = min(ans, cnt + 1);
                break;
            }
            x++;
            cnt++;
        }

        cout << ans << '\n';
    }
    return 0;
}