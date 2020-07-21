#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1000;

int n;
int cost[N][3];
int dp[N][3][3];

// 첫번째 색이 first고 ind의 색이 color일 때
// ind 칸을 포함해 앞으로 남은칸을 칠할 때 드는 최소 비용
// 현재까지 칠한 방식은 valid하다고 가정한다
int minCost(int ind, int color, int first) {
	if (ind == n - 1) // 마지막을 칠함
		return cost[ind][color];
	int& ref = dp[ind][color][first];
	if (ref != -1) return ref;
	int myCost = cost[ind][color];
	ref = INF;
	FOR(i, 0, 3) {
		if (i == color || (ind == n - 2 && i == first))
			continue;
		ref = min(ref, minCost(ind + 1, i, first) + myCost);
	}
	return ref;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
	memset(dp, -1, sizeof(int) * N * 3 * 3);
	cin >> n;
	FOR(i, 0, n) {
		FOR(j, 0, 3) {
			int x; cin >> x;
			cost[i][j] = x;
		}
	}

	int ans = INF;
	FOR(i, 0, 3)
		ans = min(ans, minCost(0, i, i));
	cout << ans << "\n";
	
    return 0;
}