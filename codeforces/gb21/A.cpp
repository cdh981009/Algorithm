#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 101;

int n;
int arr[N];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        FOR_(i, 0, 100)
            arr[i] = 0;
        FOR(i, 0, n) {
            int x;
            cin >> x;
            if (x < 0) x = -x;
            arr[x] += 1;
        }
        int ans = 0;
        FOR_(i, 0, 100) {
            int x = arr[i];
            if (!x)
            continue;
            if (i == 0) {
                ans++;
            } else {
                if (x >= 2)
                    ans += 2;
                else
                    ans += 1;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}