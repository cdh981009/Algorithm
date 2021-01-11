// 1644: Sum of Consecutive Prime Numbers
// https://www.acmicpc.net/problem/1644
#include <bits/stdc++.h>

using namespace std;

#define INF (2e9 + 1)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 4e6 + 1;

int n;

bool isPrime[N];
vector<int> primes;

void sieve() {
    FOR(i, 0, N) {
        isPrime[i] = true;
    }
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i < N; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j < N; j += i) {
                isPrime[j] = false;
            }
        }
    }

    FOR(i, 0, N) {
        if (isPrime[i])
            primes.push_back(i);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    sieve();

    cin >> n;

    int cnt = 0;
    
    int l, r, sum;
    l = r = 0;
    sum = primes[0];

    int sz = primes.size();

    while (l <= r) {
        if (sum == n) cnt++;
        if (sum >= n) {
            sum -= primes[l];
            l++;
        } else {
            if (r + 1 >= sz)
                break;
            r++;
            sum += primes[r];
        }
    }

    cout << cnt << '\n';

    return 0;
}