// 15718: 돌아온 떡파이어
// https://www.acmicpc.net/problem/15718
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

// chinese remainder theorem

// 100007 = 97 * 1031
constexpr int M = 100007;
constexpr int P0 = 97;
constexpr int P1 = 1031;

int dp0[100][100];
int dp1[1040][1040];

int modPow(int a, int b, int m) {
    int ret = 1;
	int base = a;
	
	while (b) {
		if (b % 2)
			ret = (ret * base) % m;	
		base = (base * base) % m;
		
		b /= 2;
	}
	
	return ret;
}

int c0(int n, int r) {
    if (r > n) return 0;
    if (2 * r > n) r = n - r;
    if (r == 0) return 1;
    int& ref = dp0[n][r];
    if (ref != -1) return ref;
    return ref = (c0(n - 1, r - 1) + c0(n - 1, r)) % P0;
}

int c1(int n, int r) {
    if (r > n) return 0;
    if (2 * r > n) r = n - r;
    if (r == 0) return 1;
    int& ref = dp1[n][r];
    if (ref != -1) return ref;
    return ref = (c1(n - 1, r - 1) + c1(n - 1, r)) % P1;
}

// Lucas' theorem
// (n, m) mod p = PI(ni, mi) mod p
// n = sigma(ni * p^i);
// m = sigma(mi * p^i);
int luca(int n, int m, int p) {
    int ret = 1;
    while (true) {
        int ni = n % p;
        int mi = m % p;

        ret *= (p == P0 ? c0(ni, mi) : c1(ni, mi));
		ret %= p;

        n /= p;
        m /= p;

        if (n == 0 && m == 0)
            break;
    }
    return ret;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(dp0, -1, sizeof(int) * 100 * 100);
    memset(dp1, -1, sizeof(int) * 1040 * 1040);

    int tc; cin >> tc;
    while (tc--) {
        int n, m; cin >> n >> m;
        // ans = (n - 1, m - 2) % 100007
        int ans;
		
		if (n == 0) {
			ans = m == 1 ? 1 : 0;
		} else if (m == 1) {
            ans = n == 0 ? 1 : 0;
        } else if (m == n + 1) {
            ans = 1;
        } else {
            int a0 = luca(n - 1, m - 2, P0);
            int a1 = luca(n - 1, m - 2, P1);

            // x = sigma(ai * inv(Ni, ni) * Ni)
            // inv(Ni, ni) = Ni ^ (ni - 2) (if ni is prime)
            ans = (a0 * modPow(P1, P0 - 2, P0) * P1);
			ans %= M;
        	ans += (a1 * modPow(P0, P1 - 2, P1) * P0) % M;
            ans %= M;
        }

        cout << ans << '\n';
    }

    return 0;
}