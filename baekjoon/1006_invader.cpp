// 1006: 습격자 초라기
// https://www.acmicpc.net/problem/1006
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e4;

int n, w;
int arr[N][2];
int dp[N][4][4];

// 환형으로 이어진 그래프에서 연결된 node 두개를 묶어서 선택할 수 있을 때
// 이 선택을 최대한 많이 하고자 한다
//
// dp[i][prev][fisrt]:
// n - 1 줄에서 선택된 상태가 first고
// i - 1 줄에서 선택된 상태가 prev일 때
// i 줄 앞으로 잘 묶어 선택해서 가장 많이 선택할 때 선택 수
int getDp(int i, int prev, int first) {
    int& ref = dp[i][prev][first];
    if (ref != -1)
        return ref;

    bool h = (arr[i][0] + arr[i][1] <= w);
    bool left = !(prev & (1 << 1)) && (arr[(i - 1 + n) % n][0] + arr[i][0] <= w);
    bool right = !(prev & (1 << 0)) && (arr[(i - 1 + n) % n][1] + arr[i][1] <= w);

    // 마지막 state를 first와 같은 state로 만들어야함
    // 만들 수 없으면 -INF 반환
    if (i == n - 1) {
        if (first == 0) {
            return ref = 0;
        }
        if (first == 1) {
            return right ? 1 : -INF;
        }
        if (first == 2) {
            return left ? 1 : -INF;
        }
        if (first == 3) {
            return max(
                left && right ? 2 : -INF,
                h ? 1 : -INF
                );
        }
    }

    ref = getDp(i + 1, 0, first);

    if (left) {
        ref = max(ref, getDp(i + 1, 2, first) + 1);
    }

    if (right) {
        ref = max(ref, getDp(i + 1, 1, first) + 1);
    }

    if (h) {
        ref = max(ref, getDp(i + 1, 3, first) + 1);
    }

    if (left && right) {
        ref = max(ref, getDp(i + 1, 3, first) + 2);
    }

    return ref;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        memset(dp, -1, sizeof(int) * N * 4 * 4);

        cin >> n >> w;
        FOR(i, 0, 2) {
            FOR(j, 0, n) {
                cin >> arr[j][i];
            }
        }

        int ans = 0;
        FOR(i, 0, 4) {
            ans = max(ans, getDp(0, i, i));
        }

        //cout << ans << '\n';
        cout << (2 * n - 2 * ans) + ans << '\n';
    }

    return 0;
}