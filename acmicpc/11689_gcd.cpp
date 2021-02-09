// 11689: GCD(n, k) = 1
// https://www.acmicpc.net/problem/11689
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

long long pow(long long x, int a) {
    long long ret = 1;
    long long base = x;

    while (a) {
        if (a % 2) {
            ret *= base;
        }
        base *= base;
        a /= 2;
    }

    return ret;
}

// Euler's totient function
int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n; cin >> n;
    map<long long, int> primes;

    // prime factorization: O(sqrt(n))
    // number of primes: O(log n)
    for (long long x = 2; x * x <= n; ++x) {
        while (n % x == 0) {
            primes[x] += 1;
            n /= x;
        }
    }
    if (n != 1)
        primes[n] += 1;

    long long ans = 1;

    // Euler's totient function
    // pi(n) = PI(pi^(ai - 1)(pi - 1))
    for (auto& x : primes) {
        long long p = x.first;
        int a = x.second;

        ans *= pow(p, a - 1) * (p - 1);
    }

    cout << ans << '\n';
    
    return 0;
}