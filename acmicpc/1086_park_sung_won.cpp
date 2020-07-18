#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 15;
constexpr int K = 100;
constexpr int L = 50;

int n, k;
string arr[N];
long long dp[(1 << N)][K];
int modCache[N];
int powModCache[K][L + 1];

long long gcd(long long a, long long b) {
	if (a < b) swap(a, b);
	if (b == 0) return a;
	return gcd(b, a % b);
}

long long count(int state, int remainder) {
	//cout << bitset<15>(state) << " " << remainder << endl;
	if (state == (1 << n) - 1)
		return remainder == 0 ? 1 : 0;
	long long& ref = dp[state][remainder];
	if (ref != -1) return ref;
	ref = 0;
	FOR(i, 0, n) {
		if (state & (1 << i)) continue;
		int r = remainder;
		r *= powModCache[r][arr[i].size()];
		r += modCache[i];
		r %= k;
		// cout << i << " " << bitset<15>(state) << " " << newRemainder << endl;
		ref += count(state | (1 << i), r);
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
		string x; cin >> x;
		arr[i] = x;
		denom *= (i + 1);
	}
	cin >> k;

	FOR(i, 0, n) {
		string& num = arr[i];
		int& ref = modCache[i] = 0;
		FOR(j, 0, num.size()) {
			ref *= 10;
			ref += num[j] - '0';
			ref %= k;
			//cout << j << " " << ref << endl;;
		}
		//cout << num << " " << k << " " << ref << endl; 
	}

	FOR(i, 0, k) {
		int r = i;
		FOR_(j, 1, L) {
			r *= 10;
			r %= k;
			powModCache[i][j] = r;
			cout << i << " " << j << " " << r << endl;
		}
	}

	long long cnt = count(0, 0);
	long long diviser = gcd(cnt, denom);
	cout << cnt / diviser << "/" << denom / diviser << "\n";
	
    return 0;
}