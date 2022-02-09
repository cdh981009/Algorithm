#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 1000;
constexpr int M = 998244353;

int n, m;
ll ans;
ll dp[N][12][12][12];

// dp[i][a1][a2][a3]
// 길이가 x인 lis가 이미 array에 있을 때 해당 lis 의 끝 중 가장 작은것: ax
ll getDp(int i, int m1, int m2, int m3) {
    if (i == n) return (m3 != 11 ? 1 : 0);

    ll& ref = dp[i][m1][m2][m3];
    if (ref != -1) return ref;
    ref = 0;

    FOR_(num, 1, m) {
        if (num > m3) continue;
        
        if (num > m2) { // (m2, m3]
            ref += getDp(i + 1, m1, m2, num);
        } else if (num > m1) { // (m1, m2]
            ref += getDp(i + 1, m1, num, m3);
        } else { // (1, m1]
            ref += getDp(i + 1, num, m2, m3);
        }

        ref %= M;
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

    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    cout << getDp(0, 11, 11, 11) << '\n';
    return 0;
}