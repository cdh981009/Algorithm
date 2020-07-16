#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 16;
int n;
int dp[N][N][(1 << N) - 1];
int weight[N][N];

// start에서 시작한 외판원이 status만큼(bit mask) 방문하고 현재 curr일 때
// 앞으로 순환을 마칠 때 드는 최소 비용
int getCost(int start, int curr, int status) {
    if (status == (1 << n) - 1) // 모든 곳 방문
        return (weight[curr][start] == 0 ? INF : weight[curr][start]); // 다시 첫 지점으로 돌아갈 수 있어야 한다
    int &ref = dp[start][curr][status];
    if (ref != -1)
        return ref;
    ref = INF;
    FOR(i, 0, n) {
        if (status & (1 << i))
            continue;
        if (weight[curr][i] != 0) {
            // cout << start << " " << curr << " " << bitset<16>(status) << endl;
            // 방문하지 않은 곳 방문
            ref = min(ref, getCost(start, i, status | (1 << i)) + weight[curr][i]);
        }
    }
    return ref;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof(int) * N * N * ((1 << N) - 1));
    cin >> n;
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            int x; cin >> x;
            weight[i][j] = x;
        }
    }
    int ans = INF;
    FOR(i, 0, n)
        ans = min(ans, getCost(i, i, 1 << (i)));
    cout << ans << "\n";
    return 0;
}