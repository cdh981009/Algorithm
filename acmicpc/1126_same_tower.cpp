//1126: 같은 탑
// https://www.acmicpc.net/problem/1126
#include <bits/stdc++.h>

using namespace std;

#define INF 1e6
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 50;
constexpr int X = 5e5;

int n;
int arr[N];
int dp[X + 1];
int aux[X + 1];

int solve() {
    FOR(i, 0, X + 1) {
        aux[i] = -INF;
    }
    aux[0] = 0;

    FOR(i, 0, n) {
        FOR(diff, 0, X + 1) {
            dp[diff] = aux[diff];

            if (diff + arr[i] <= X)
                dp[diff] = max(dp[diff], aux[diff + arr[i]] + arr[i]);
            
            dp[diff] = 
                max(dp[diff],
                    (diff - arr[i] >= 0) ? (aux[diff - arr[i]]) : (aux[-diff + arr[i]] + arr[i] - diff)
                );
            // cout << diff << ' ' << dp[diff] << '\n';
        }
        swap(aux, dp);
    }

    return aux[0];
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 0, n) {
        cin >> arr[i];
    }

    int ret = solve();

    cout << (ret <= 0 ? -1 : ret) << '\n';

    return 0;
}