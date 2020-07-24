#include <iostream>
#include <cstring>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e6;
int n;
int cnt[N+1];
int nextNum[N+1];

// curr을 1로 만들기 위해 앞으로 해야 하는 연산의 갯수
int makeOne(int curr) {
	if (curr == 1)
		return 0;
	int& ref = cnt[curr];
	if (ref != -1) return ref;
	ref = INF;
	FOR_(i, 1, 3) {
		int res = INF;
		if (i == 1)
			res = makeOne(curr - 1) + 1;
		else if (curr % i == 0)
			res = makeOne(curr / i) + 1;

		if (res < ref) {
			ref = res;
			nextNum[curr] = (i == 1) ? curr - 1 : curr / i;
		}
	}
	return ref;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
	memset(cnt, -1, sizeof(int) * (N + 1));
	memset(nextNum, -1, sizeof(int) * (N + 1));
	cin >> n;

	cout << makeOne(n) << "\n";
	while (n != -1) {
        cout << n << " ";
        n = nextNum[n];
	}
	cout << "\n";
	return 0;
}