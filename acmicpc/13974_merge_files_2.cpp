// 13974: 파일 합치기 2
// https://www.acmicpc.net/problem/13974
#include <bits/stdc++.h>

using namespace std;

#define INF INT64_MAX
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 5010;

int sum[N];
int pos[N][N];
long long solve[N][N];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;

    while (tc--) {
        int n; cin >> n;

        FOR_(i, 1, n) {
            int x; cin >> x;
            sum[i] = sum[i - 1] + x;
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
            pos[i][i + 1] = i;
        }

        FOR_(l, 2, n) { // round
            // round for length of i
            FOR_(i, 1, n - l) {
                int j = i + l;

                long long& ref = solve[i][j];
                int& opt = pos[i][j];
                ref = INF;
                
                FOR_(p, pos[i][j - 1], pos[i + 1][j]) {
                    long long res = solve[i][p] + solve[p + 1][j];
                    if (res < ref) {
                        ref = res;
                        opt = p;
                    }
                }

                ref += sum[j] - sum[i - 1];
            }
        }

        cout << solve[1][n] << '\n';
    }

    return 0;
}