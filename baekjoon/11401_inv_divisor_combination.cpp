#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)
int MOD = 1000000007;
int N, K;

int modPow(int a, int b, int m) {
    if (b == 0) return 1;
    long long h = modPow(a, b/2, m);
    h = (h*h) % m;
    if (b % 2 == 1) h = (h*a) % m;
    return h;
}

// m is a prime
int inv(int x, int m) {
    return modPow(x, m - 2, m);
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    long long numerator = 1;
    FOR_(i, N - K + 1, N)
        numerator = (numerator * i) % MOD;
    long long denominator = 1;
    FOR_(i, 1, K)
        denominator = (denominator * i) % MOD;
    cout << numerator * inv(denominator, MOD) % MOD << endl;
    return 0;
}