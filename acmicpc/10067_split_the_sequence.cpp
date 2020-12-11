// 10067: Split the sequence
// https://www.acmicpc.net/problem/10067
#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 5)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e5 + 1; // 1e5;
constexpr int K = 200;
int n, k;
int sum[N];
int (&a)[N] = sum;

int backTrack[N][K];
long long bPrev[N], bCurr[N];

// convex hull of previous lines
int stck[N];
int top;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    long long s = 0LL;
    FOR(i, 0, n) {
        int x;
        cin >> x;
        sum[i] = (s += x);
    }

    long long maxVal = 0;
    long long maxInd = 0;

    // fill dp[i][1]'s waiting list
    FOR(i, 0, n - 1) {
        bCurr[i] = (long long)(sum[n - 1] - sum[i]) * (sum[i]);
        if (k == 1 && bCurr[i] >= maxVal) {
            maxVal = bCurr[i];
            maxInd = i;
        }
    }

    auto crossX = [&](int r, int l) {
        return (double)(bPrev[l] - bPrev[r]) / (a[r] - a[l]);
    };

    FOR(j, 1, k) {
        swap(bCurr, bPrev);
        top = -1;

        int qInd = 0;
        /*
        dp[i][j] = max(dp[k][j - 1] + (sum[n - 1] - sum[i]) * (sum[i] - sum[k])) (for k < i)
                 = max(dp[k][j - 1] + (sum[i] - sum[n - 1]) * sum[k]) + (sum[n - 1] - sum[i]) * sum[i];
                        ^b              ^x                     ^a
        */
        FOR(i, j - 1, n + (j - k)) {
            if (i >= j) {
                long long s = sum[n - 1] - sum[i];

                while (qInd + 1 <= top && crossX(stck[qInd], stck[qInd + 1]) <= -s) {
                    qInd++;
                }

                int l = stck[qInd];
                long long dp = bPrev[l] + s * ((long long)sum[i] - sum[l]);

                backTrack[i][j] = l;

                if (dp >= maxVal) {
                    maxVal = dp;
                    maxInd = i;
                }

                bCurr[i] = dp;
            }

            // put an element from waiting list (prev) to stack
            // check parallel line
            if (top >= 0 && sum[i] == sum[stck[top]]) {
                if (bPrev[i] < bPrev[stck[top]]) {
                    // this line is better
                    top--;
                } else {
                    // this line is useless
                    // skip this line
                    continue;
                }
            }

            stck[++top] = i;

            while (top >= 2 && crossX(stck[top], stck[top - 1]) <= crossX(stck[top - 1], stck[top - 2])) {
                stck[top - 1] = stck[top];
                top--;
            }
        }
    }

    cout << maxVal << '\n';

    int ind = maxInd;
    FOR(i, 0, k) {
        cout << (ind + 1) << " ";
        ind = backTrack[ind][k - i - 1];
    }
    cout << '\n';

    return 0;
}