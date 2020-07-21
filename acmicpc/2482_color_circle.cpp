#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1000;
constexpr int M = 1e9 + 3;
int n, k;
int cntDp[N][N][2][2];

// cntDp[ind][remain][isPicked][isFirstPicked]
// ind번째 색 이후로 선택해야 할 색 갯수가 remain일 때
// 앞으로 선택할 수 있는 가짓 수 갯수
int count(int ind, int remain, bool isPicked, bool isFirstPicked) {
	if (ind == n - 1) // 모두 결정 됨
		return remain == 0 ? 1 : 0;
	int& ref = cntDp[ind][remain][isPicked][isFirstPicked];
	if (ref != -1)
		return ref;
	ref = 0;
	ref += count(ind + 1, remain, false, isFirstPicked); // 다음걸 고르지 않음
	if (isPicked == false && (ind != n - 2 || isFirstPicked == false)) {
		ref += count(ind + 1, remain - 1, true, isFirstPicked); // 다음걸 고름
	}
	ref %= M;
	return ref;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
	memset(cntDp, -1, sizeof(int) * N * N * 2 * 2);
	cin >> n >> k;
	if (k > n/2) {
		cout << 0 << "\n";
	} else {
		int ans = count(0, k, false, false) + count(0, k - 1, true, true);
		ans %= M;
		cout << ans << "\n";
	}
    return 0;
}