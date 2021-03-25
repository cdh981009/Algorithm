#include <iostream>
#include <cstring>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e3;
int n;
int arr[N + 1];
int nextInd[N + 1];
int len[N + 1];

int lis(int ind) {
	int& ref = len[ind];
	if (ref != -1) return ref;
	ref = 1;
	FOR_(i, ind + 1, n) {
		if (arr[ind] < arr[i]) {
			int res = lis(i) + 1;
			if (res > ref) {
				ref = res;
				nextInd[ind] = i;
			}
		}
	}
	return ref;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
	memset(len, -1, sizeof(int) * (N + 1));
	memset(nextInd, -1, sizeof(int) * (N + 1));
	cin >> n;

	arr[0] = 0;
	FOR(i, 0, n) {
		int x; cin >> x;
		arr[i + 1] = x;
	}
	cout << lis(0) - 1 << "\n";
	int curr = nextInd[0];
	while (curr != -1) {
		cout << arr[curr] << " ";
		curr = nextInd[curr];
	}
	cout << "\n";

	return 0;
}