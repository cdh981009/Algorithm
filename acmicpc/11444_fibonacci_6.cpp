// 11444: 피보나치 수 6
// https://www.acmicpc.net/problem/11444
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int M = 1e9+7;

struct Mat4x4 {
	long long arr[2][2] = {
		1, 0,
		0, 1
	};
};


Mat4x4 operator*(const Mat4x4& l, const Mat4x4& r) {
	Mat4x4 m = {
		((l.arr[0][0] * r.arr[0][0]) % M + (l.arr[0][1] * r.arr[1][0]) % M) % M,
		((l.arr[0][0] * r.arr[0][1]) % M + (l.arr[0][1] * r.arr[1][1]) % M) % M,
		((l.arr[1][0] * r.arr[0][0]) % M + (l.arr[1][1] * r.arr[1][0]) % M) % M,
		((l.arr[1][0] * r.arr[0][1]) % M + (l.arr[1][1] * r.arr[1][1]) % M) % M
	};
	
	return m;
}

// calculate mat ^ n
Mat4x4 matModPow(long long n) {
	Mat4x4 mat = {
		1, 1,
		1, 0
	};
	Mat4x4 ret;
	
	while (n > 0) {
		if (n % 2) {
			ret = ret * mat;
		}
		mat = mat * mat;
		n /= 2;
	}
	
	return ret;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n; cin >> n;
	
	long long ans;
	
	if (n == 1LL) {
		ans = 1;
	} else {
		auto m = matModPow(n - 1);
		ans = m.arr[0][0];
	}
	
	cout << ans << '\n';

    return 0;
}