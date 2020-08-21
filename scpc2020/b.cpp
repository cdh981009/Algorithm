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
int dp[N + 1][N + 1];
int a[N + 1];
int b[N + 1];

bool state(int i, int j) {
    if (i == 0 && j == 0)
        return true;
    int& ref = dp[i][j];
    if (ref != -1)
        return ref;
    ref = false;
    // 다음 state 하나라도 false면 true
    // 모두 true면 false
    int sum = 0;
    int cnt = 0;
    while (i > cnt && (sum += a[i - cnt]) <= k) {
        ++cnt;
        if (!state(i - cnt, j)) {
            ref = true;
            break;
        }
    }
    sum = 0; cnt = 0;
    while (j > cnt && (sum += b[j - cnt]) <= k) {
        ++cnt;
        if (!state(i, j - cnt)) {
            ref = true;
            break;
        }
    }

    return ref;
}

int main(int argc, char** argv) {
    int T, test_case;
    freopen("input.txt", "r", stdin);

    cin >> T;
    for (test_case = 0; test_case < T; test_case++) {
        Answer = 0;
        memset(dp, -1, sizeof(int) * (N + 1) * (N + 1));
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a[i + 1] = x;
        }
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            b[i + 1] = x;
        }
        FOR_(i, 0, n)
            FOR_(j, 0, n)
                Answer += state(i, j);
        cout << "Case #" << test_case + 1 << endl;
        cout << Answer << " " << (n + 1) * (n + 1) - Answer << endl;
    }

    return 0; //Your program should return 0 on normal termination.
}