// 4149: factoring large number
// https://www.acmicpc.net/problem/4149
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ull = unsigned long long;

vector<ull> primeFactors;

ull gcd(ull a, ull b) {
    if (a < b)
        swap(a, b);
        
    while (true) {
        // a > b
        if (b == 0)
            return a;
        a = a % b;
        swap(a, b);
    }
}

inline ull modMul(ull x, ull y, ull m) {
    return ((__int128_t)x * y) % m;
}

ull modPow(ull a, ull n, ull m) {
    ull h = 1ULL;
    while (n > 0ULL) {
        if (n % 2ULL)
            h = modMul(h, a, m);
        a = modMul(a, a, m);
        n /= 2ULL;
    }
    return h;
}

ull rho(ull n) {
    ull x, y, c, g = n;

    auto f = [&](ull x) -> ull {
        return (modMul(x, x, n) + c) % n;
    };

    while (g == 1ULL || g == n) {
        if (g == n) {
            x = y = (ull)rand() % (n - 1ULL) + 1ULL;
            c = (ull)rand() % (n - 1ULL) + 1ULL;
            g = 1;
        }

        x = f(x);
        y = f(f(y));
        g = gcd(x > y ? x - y : y - x, n);
    }

    return g;
}

bool miller(ull n) {
    const static int aList[12] =
            {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

    for (int i = 0; i < 12; ++i) {
        auto a = aList[i];
        if (a >= n)
            break;

        auto k = n - 1;
        while (true) {
            auto temp = modPow(a, k, n);
            if (temp != 1 && temp != n - 1)
                return false;

            if (temp == n - 1)
                break;

            if (k % 2)
                break;

            k /= 2;
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ull n;
    cin >> n;

    while (n % 2 == 0) {
        n /= 2;
        primeFactors.push_back(2);
    }

    if (n != 1) {
        vector<ull> factors;
        factors.push_back(n);

        srand(time(NULL));

        while (!factors.empty()) {
            ull x = factors.back();
            factors.pop_back();

            if (x % 2ULL && miller(x)) { // prime
                primeFactors.push_back(x);
            } else { // very big and not prime
                if (x % 2ULL) {
                    ull f1 = rho(x);
                    ull f2 = x / f1;
                    factors.push_back(f1);
                    factors.push_back(f2);
                } else {
                    primeFactors.push_back(2);
                    factors.push_back(x / 2);
                }
            }
        }

        sort(primeFactors.begin(), primeFactors.end());
    }

    for (auto x : primeFactors) {
        cout << x << "\n";
    }

    return 0;
}