#include <bits/stdc++.h>

using namespace std;

#define INF INT32_MAX
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e7;

using pii = pair<int, int>;
using ll = long long;

ll n;
ll ans;
ll arr[N];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    FOR(i, 1, N) {
        arr[i] = arr[i - 1] + i - 1;
    }

    int tc; cin >> tc;
    
    FOR_(caseNum, 1, tc) {
        cin >> n;
        ans = 0;
        FOR(len, 1, N) {
            if (arr[len] >= n) {
                break;
            }
            ll x = n - arr[len];
            if (x % len == 0) {
                ans++;
                //cout << x / len << ' ';
            }
        }

        cout << "Case #" << caseNum << ": " << ans << '\n';
    }
    return 0;
}