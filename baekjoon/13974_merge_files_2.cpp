// 13974: 파일 합치기 2
// https://www.acmicpc.net/problem/13974
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 5001;

int tc, n;

int sum[N];
int pos[N];
int solve[N][N];

int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    scanf("%d", &tc);

    while (tc--) {
        scanf("%d", &n);

        FOR_(i, 1, n) {
            scanf("%d", &sum[i]);
            sum[i] += sum[i - 1];
        }
        
        // knuth optimization technique
        // pos(i, j - 1) <= pos(i, j) <= pos(i + 1, j)
        // pos(i, i + 1) = i
        //
        // solve(i, i + 1) = sum(i, i + 1)
        // solve(i, j) = min(sum(i, j) + solve(i, p) + solve(p + 1, j)) for (i <= p < j)

        // base
        FOR_(i, 1, n - 1) {
            solve[i][i + 1] = sum[i + 1] - sum[i - 1];
            pos[i] = i;
        }

        FOR_(l, 2, n - 1) {
            FOR_(i, 1, n - l) {
                int j = i + l;
                int ans = INT32_MAX;
                int opt;

                for (int p = pos[i]; p <= pos[i + 1]; ++p) {
                    // todo: improve caching
                    int res = solve[i][p] + solve[p + 1][j];
                    if (res < ans) {
                        ans = res;
                        opt = p;
                    }
                }

                pos[i] = opt;
                solve[i][j] = sum[j] - sum[i - 1] + ans;
            }
        }

        printf("%d\n", solve[1][n]);
    }

    return 0;
}