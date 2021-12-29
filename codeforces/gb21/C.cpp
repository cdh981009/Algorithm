#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 101;

int n;
int arr[N];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        FOR(i, 0, n) {
            cin >> arr[i];
        }

        if (n == 1) {
            cout << 0 << '\n';
            continue;
        }
        
        int ans = n;
        FOR(i, 0, n) {
            FOR(j, i + 1, n) {
                double d = (double)(arr[j] - arr[i]) / (j - i);
                //cout << d << '\n';
                int cnt = 0;

                FOR(k, 0, n) {
                    if (k == i || k == j)
                        continue;
                    
                    double m = arr[i] + d * (k - i);
                    if (arr[k] != m)
                        cnt++;
                }

                ans = min(cnt, ans);
            }
        }

        cout << ans << '\n';
    }
    return 0;
}