#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 201010;
pii arr[N];
int cnt[N];
int ans[N];
int n, k;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n >> k;
        memset(cnt, 0, sizeof(int) * n);
        memset(ans, 0, sizeof(int) * n);
        FOR(i, 0, n) {
            int x; cin >> x;
            x--;
            arr[i] = {x, i};
            cnt[x] = min(k, cnt[x] + 1);
        }
        int c = 0;
        FOR(i, 0, n) {
            c += cnt[i];
        }
        c = c - c % k;

        sort(arr, arr + n);
        int x = 1;
        int y = 0;
        int z = 0;
        FOR(i, 0, n) {
            if (arr[i - 1].first != arr[i].first) {
                y = 0;
            }
            
            if (y == k) {
                continue;
            }

            ans[arr[i].second] = x;
            y++;
            x++;
            z++;

            if (x > k)
                x = 1;
            
            if (z == c)
                break;
        }

        FOR(i, 0, n) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}