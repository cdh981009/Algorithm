#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)
constexpr int N = 15;
constexpr int K = 100;

int n, k;
int arr[N];
long long dp[(1 << N)][K];

long long gcd(long long a, long long b) {
	if (a < b) swap(a, b);
	if (b == 0) return a;
	return gcd(b, a % b);
}

int digit(long long x) {
	int cnt = 0;
	while (x > 0) {
		x = x/10;
		cnt++;
	}
	return cnt;
}

long long count(int state, int remainder) {
	if (state == (1 << (n + 1)) - 1)
		return remainder == 0;
	cout << bitset<15>(state) << " " << remainder << endl;
	long long& ref = dp[state][remainder];
	if (ref != -1) return ref;
	FOR(i, 0, n) {
		if (state & (1 << i)) continue;
		long long newRemainder = remainder;
		FOR(i, 0, digit(arr[i]))
			newRemainder *= 10;
		newRemainder += arr[i];
		newRemainder %= k;
		cout << i << " " << bitset<15>(state) << " " << newRemainder << endl;
		ref += count(state | (1 << i), newRemainder);
	}
	return ref;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
	memset(dp, -1, sizeof(long long) * (1 << N) * K);
	cin >> n;
	long long denom = 1;
	FOR(i, 0, n) {
		long long x; cin >> x;
		arr[i] = x;
		denom *= (i + 1);
	}
	cin >> k;
	long long cnt = count(0, 0);
	long long diviser = gcd(cnt, denom);
	cout << cnt / diviser << "/" << denom / diviser << "\n";
	
    return 0;
}