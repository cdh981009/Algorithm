#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 101;

int n;
vector<int> v;
int dp[N][N];

int getDp(int s, int e) {
    if (s == e) return v[s] == 0 ? 2 : 1;
    if (s > e) return 0;

    int& ref = dp[s][e];
    if (ref != -1) return ref;
    ref = 0;

    int cnt[110] = {0,};
    FOR_(i, s, e) {
        if (v[i] <= 100)
            cnt[v[i]]++;
        FOR_(j, 0, 100) {
            if (cnt[j] == 0) {
                ref = max(ref, 1 + j + getDp(i + 1, e));
                break;
            }
        }
    }
    return ref;
}

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
        int n; cin >> n;
        v = vector<int>(n);
        memset(dp, -1, sizeof(dp));
        FOR(i, 0, n) {
            cin >> v[i];
        }
        ll ans = 0;
        
        FOR(i, 0, n) {
            FOR(j, i, n) {
                cout << i << ' ' << j << ' ' << getDp(i, j) << '\n';
                ans += getDp(i, j);
            }
        }

        cout << ans << '\n';
    }
    return 0;
}