#include <bits/stdc++.h>

using namespace std;

#define INF INT32_MAX
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 100000;
constexpr int M = 1e9 + 7;

using pii = pair<int, int>;
using ll = long long;

int n, k;
string str;
ll ans;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    FOR_(caseNum, 1, tc) {
        ans = 0;
        cin >> n >> k >> str;

        // self
        ans = 1;
        int len = (n + 1) / 2;
        FOR(i, 0, len) {
            int org = n - len + i;
            int pal = (n - 1) / 2 - i;
            if (str[org] < str[pal]) {
                ans = 0;
                break;
            } else if (str[org] > str[pal]) {
                break;
            } else if (i == len - 1) {
                ans = 0;
            }
        }

        ll base = 1;
        for (int i = len - 1; i >= 0; --i) {
            ll x = str[i] - 'a';
            x *= base;
            x %= M;
            ans += x;
            ans %= M;
            base *= k;
            base %= M;
        }

        cout << "Case #" << caseNum << ": " << ans << '\n';
    }
    return 0;
}