#include <bits/stdc++.h>

using namespace std;

#define INF 1e18
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 2400;
constexpr int M = 30;

using ll = long long;
using pii = pair<int, int>;

int k, n;

bool prime[N];
vector<int> primes;

void init() {
    FOR(i, 2, N) {
        prime[i] = true;
    }
    for (int i = 2; i * i < N; ++i) {
        if (prime[i]) {
            for (int j = i * i; j < N; j += i) {
                prime[j] = false;
            }
        }
    }

    FOR(i, 2000, N) {
        if (prime[i]) {
            primes.push_back(i);
            if (primes.size() == 30)
                break;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    init();
    cin >> k >> n;

    FOR(i, 0, k) {
        int a = primes[i];
        FOR(j, 0, n) {
            cout << 1 + j * a << ' ';
        }
        cout << '\n';
    }

    return 0;
}