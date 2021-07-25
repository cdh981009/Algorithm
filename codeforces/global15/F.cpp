#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 201010;
constexpr int M = 998244353;

int n;
bool init[N];
int delta[N];
int pos[N];
int amount[N];
int pre[N];
ll ans;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 0, n) {
        int x, y, s;
        cin >> x >> y >> s;
        delta[i] = x - y;
        init[i] = s;
        pos[i] = x;
        amount[i] = delta[i];
    }

    ans = (pos[n - 1] + 1) % M;
    FOR(i, 0, n) {
        int y = pos[i] - delta[i];
        if (i == 0) {
            pre[i] = amount[i];
        } else {
            int j = lower_bound(pos, pos + n, y) - pos;
            if (j < i) {
                amount[i] = ((ll) amount[i] + pre[i - 1] - (j == 0 ? 0 : pre[j - 1]) + M) % M;
            }
            pre[i] = ((ll) amount[i] + pre[i - 1]) % M;
        }
        
        if (init[i] != 0)
            ans = (ans + amount[i]) % M;
    }

    cout << ans << '\n';

    return 0;
}