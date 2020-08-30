#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 3e3;
int Answer;
int n, k;
bool dp[N + 1][N + 1];
int a[N + 1];
int b[N + 1];
int xLen[N + 1];
int yLen[N + 1];
// false count
int xCnt[N + 1][N + 1];
int yCnt[N + 1][N + 1];

int main(int argc, char** argv) {
    int T, test_case;
    freopen("input.txt", "r", stdin);

    cin >> T;
    for (test_case = 0; test_case < T; test_case++) {
        Answer = 0;
        memset(xCnt, 0, sizeof(int) * (N + 1) * (N + 1));
        memset(yCnt, 0, sizeof(int) * (N + 1) * (N + 1));
        cin >> n >> k;
        int kLen = 0;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a[i + 1] = x;
            sum += x;
            while (sum > k) {
                sum -= a[i + 1 - kLen];
                --kLen;
            }
            ++kLen;
            xLen[i + 1] = kLen;
        }
        kLen = sum = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            b[i + 1] = x;
            sum += x;
            while (sum > k) {
                sum -= b[i + 1 - kLen];
                --kLen;
            }
            ++kLen;
            yLen[i + 1] = kLen;
        }

        dp[0][0] = true;
        ++Answer;

        FOR_(i, 0, n) {
            FOR_(j, 0, n) {
                if (i == 0 && j == 0)
                    continue;
                auto& ref = dp[i][j] = false;
                if (i > 0 &&
                        xCnt[i - 1][j] != (i - 1 - xLen[i] >= 0 ? xCnt[i - 1 - xLen[i]][j] : 0)) {
                    ref = true;
                } else if (j > 0 &&
                           yCnt[i][j - 1] != (j - 1 - yLen[j] >= 0 ? yCnt[i][j - 1 - yLen[j]] : 0)) {
                    ref = true;
                }
                xCnt[i][j] = (i > 0 ? xCnt[i - 1][j] : 0);
                yCnt[i][j] = (j > 0 ? yCnt[i][j - 1] : 0);
                if (!ref) {
                    ++xCnt[i][j];
                    ++yCnt[i][j];
                } else {
                    ++Answer;
                }
            }
        }

        cout << "Case #" << test_case + 1 << endl;
        cout << Answer << " " << (n + 1) * (n + 1) - Answer << endl;
    }

    return 0; //Your program should return 0 on normal termination.
}