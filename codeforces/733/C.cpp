#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;

constexpr int N = 101010;
int n;
int a[N];
int b[N];

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
            cin >> a[i];
        }
        FOR(i, 0, n) {
            cin >> b[i];
        }
        sort(a, a + n, greater<int>());
        sort(b, b + n, greater<int>());
        int cnt = 4 - n % 4;
        int ans = 0;
        int sa = 0;
        int sb = 0;
        int k = n - n / 4;
        int i = 0;
        FOR(i, 0, k) {
            sa += a[i];
            sb += b[i];
        }
        int ia, ib;
        ia = k - 1;
        ib = k;
        while (sa < sb) {
            ans++;
            sa += 100;
            cnt--;
            if (cnt == 0) {
                cnt = 4;
                if (ia >= 0) {
                    sa -= a[ia];
                    ia--;
                } else {
                    sa -= 100;
                }
            } else {
                if (ib < n) {
                    sb += b[ib];
                    ib++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}