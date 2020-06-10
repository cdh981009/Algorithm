#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int N, A, R, M;
vector<int> arr;

long long minCost(int k) {
	long long aCnt = 0;
	long long rCnt = 0;
	FOR(i, 0, N) {
		if (k > arr[i])
			aCnt += k - arr[i];
		else
			rCnt += arr[i] - k;
	}
	long long mCnt = 0;
	if (M < A + R) {
		mCnt = min<long long>(aCnt, rCnt);
		aCnt -= mCnt;
		rCnt -= mCnt;
	}
	return (aCnt * A) + (rCnt * R) + (mCnt * M);
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> A >> R >> M;
	arr.reserve(N);
	FOR(i, 0, N) {
		int x; cin >> x;
		arr.push_back(x);
	}
	
	/*cout << minCost(0) << endl;
	cout << minCost(1) << endl;
	cout << minCost(2) << endl;
	cout << minCost(3) << endl;
	cout << minCost(4) << endl;
	cout << minCost(5) << endl;
	cout << minCost(6) << endl;
	*/
    int minK = 0;
	int maxK = 1e9;
	int x = 0;
	for (int d = maxK; d > 0; d /= 2) {
		while (x + d <= maxK && minCost(x + d) >= minCost(x + d + 1)) {
			x += d;
		}
	}
	// cout << x + 1 << endl;
	cout << minCost(x + 1) << endl;
    return 0;
}