#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)
int N, K;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
	vector<int> coins;
	coins.reserve(N);
	FOR(i, 0, N) {
		int x; cin >> x;
		coins.push_back(x);
	}
	vector<int> dp(K + 1, 0);
	dp[0] = 1;
	/*
	n번째 코인을 쓰거나 안써서 값 k를 만드는 경우의 수: 
	코인을 전혀 안쓰는 경우에 값 k를 만들거나, 코인을 적어도 하나 쓰고 값 k-coin[n]를 만드는 경우의 수의 합
	dp[n][k] = dp[n-1][k] + dp[n][k-coin[n]]
	만약 n-1 번째 level에서 dp 값이 다 구해졌다면,
	dp[k] = dp[k] + dp[k-coin[n]]
	(이 때 dp[k-coin[n]]이 nth level에서의 값 이어야 한다. 즉 이미 계산이 되어 있어야 하므로, bottom-up 으로 값을 구해야 함)
	*/
	FOR(i, 0, N)
		for (int j = 1; j <= K; ++j) // bottom-up
			if (j - coins[i] >= 0)
				dp[j] += dp[j - coins[i]];
	
	cout << dp[K] << "\n";
    return 0;
}