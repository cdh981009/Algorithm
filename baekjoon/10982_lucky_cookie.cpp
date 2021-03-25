// 10982: 행운쿠기 제작소
// https://www.acmicpc.net/problem/10982
#include <bits/stdc++.h>

using namespace std;

#define INF 1e6
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1000;
constexpr int M = 10101;

int n;
int arr[N][2];
int dp[M][2];
int aux[M][2];

int solve() {
    FOR(i, 0, M) {
        aux[i][0] = aux[i][1] = i;
    }

    FOR(i, 0, n) {
        FOR(j, 0, M) {
            FOR(k, 0, 2) {
                int &ref = dp[j][k];
                ref = INF;
                if (j + arr[i][k] < M)
                    ref = min(ref, aux[j + arr[i][k]][k]);
                if (j - arr[i][1 - k] < 0)
                    ref = min(ref, aux[arr[i][1 - k] - j][1 - k] + j);
                else
                    ref = min(ref, aux[j - arr[i][1 - k]][k] + arr[i][1 - k]);
            }
        }
        swap(dp, aux);
    }
    
    return aux[0][0];
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;

    while (tc--) {
        cin >> n;
        FOR(i, 0, n) {
            cin >> arr[i][0] >> arr[i][1];
        }

        cout << solve() << '\n';
    }

    return 0;
}