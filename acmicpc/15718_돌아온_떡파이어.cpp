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

int dp0[P0 + 1][P0 + 1];
int dp1[P1 + 1][P1 + 1];

// (x ^ a) mod m
int modpow(int x, int a, int m) {
    long long base = x;
    long long ret = 1;

    while (a) {
        if (a % 2)
            ret = (ret * base) % m;
        base = (base * base) % m;
        a /= 2;
    }

    return ret;
}

int inv(int x, int a) {
    // a is prime
    return modpow(x, a - 2, a);
}

int c97(int n, int r) {
    if (r > n) return 0;
    if (2 * r > n) r = n - r;
    if (r == 0) return 1;
    int& ref = dp0[n][r];
    if (ref != -1) return ref;
    return ref = (c97(n - 1, r - 1) + c97(n - 1, r)) % P0;
}

int c1031(int n, int r) {
    if (r > n) return 0;
    if (2 * r > n) r = n - r;
    if (r == 0) return 1;
    int& ref = dp1[n][r];
    if (ref != -1) return ref;
    return ref = (c1031(n - 1, r - 1) + c1031(n - 1, r)) % P1;
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

        ret *= (p == P0 ? c97(ni, mi) : c1031(ni, mi)) % p;

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

    memset(dp0, -1, sizeof(int) * (P0 + 1) * (P0 + 1));
    memset(dp1, -1, sizeof(int) * (P1 + 1) * (P1 + 1));

    int tc; cin >> tc;
    while (tc--) {
        int n, m; cin >> n >> m;
        // ans = (n - 1, m - 2) % 100007
        int ans;

        if (m - 2 > n - 1) {
            ans = 0;
        } else if (m - 2 == n - 1) {
            ans = 1;
        } else {
            int a0 = luca(n - 1, m - 2, P0);
            int a1 = luca(n - 1, m - 2, P1);

            // x = sigma(ai * inv(Ni, ni) * Ni)
            // inv(Ni, ni) = Ni ^ (ni - 2) (if ni is prime)
            ans = (a0 * inv(P1, P0) * P1) % M +
                  (a1 * inv(P0, P1) * P0) % M;
            ans %= M;
        }

        cout << ans << '\n';
    }

    return 0;
}