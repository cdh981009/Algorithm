#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 302;
constexpr int M = 998244353;

int n, k;
vector<pii> v;
ll dp[N][N][N];

/*
    dp[i][j][k] 
    [0...i-1] 원소는 이미 고려한 상황. 그중 고르지 않은 원소중 x.q가 가장 작은것이 k
    i번째 원소를 고려하고, 앞으로 j개를 선택해야 할 때 
    i번째 원소를 고르려면, [0....i-1]개 원소중 고르지 않은 원소 모든 x에 대해 x.q > i.q 여야 한다
    고르지 않은 원소 x중 min(x.q)만 고려하면 되므로 이것이 k

    알맞게 고르는 경우의 수
*/

ll getDp(int i, int j, int k) {
    if (j == 0) return 1;
    if (i == n)
        return j == 0;

    ll& ref = dp[i][j][k];
    if (ref != -1) return ref;

    // i번째 원소를 고르지 않음
    ref = getDp(i + 1, j, min(k, v[i].second));
    // i번재 원소를 고르려면 k > v[i].second
    if (k > v[i].second) {
        ref += getDp(i + 1, j - 1, k);
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

    cin >> n >> k;
    v.resize(n);

    memset(dp, -1, sizeof(dp));
    FOR(i, 0, n) cin >> v[i].first;
    FOR(i, 0, n) cin >> v[i].second;

    sort(v.begin(), v.end());

    cout << getDp(0, k, n + 1) << '\n';

    return 0;
}