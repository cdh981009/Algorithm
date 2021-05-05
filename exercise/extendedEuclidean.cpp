// 3955: Candy Distribution
// https://www.acmicpc.net/problem/3955
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

// extended euclidean algorithm
// ax + by = gcd(a, b)
// gcd(a, b) = gcd(b, a % b)
// a % b = a - (a / b) * b
// -> bx' + (a - (a / b) * b)y' = gcd(a, b)
// -> ay' + b(x' - (a / b)y') = gcd(a, b)
// x = y'
// y = x' - (a / b)y'

// diophantine equation
// ax + by = c
// iif c = k * gcd(a, b)
// solve: ax' + by' = gcd(a, b)
// x = kx', y = ky'
//
// a = p * gcd(a, b)
// b = q * gcd(a, b)
// 임을 이용하면
// { x', y' } = { x0 + n * q, y0 - n * p }
// 로 다른 답을 만들 수 있다

using ll = long long;

// solve ax + by = gcd(a, b);
tuple<ll, ll, ll> gcd(int a, int b) {
    ll x, y, g;

    if (b == 0)
        return {1, 0, a};

    tie(x, y, g) = gcd(b, a % b);
    return {y, x - (a / b) * y, g};
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int k, c;
        cin >> k >> c;
        // k * x + c * y = 1;
        long long x, y, g;
        bool impossible = false;

        tie(x, y, g) = gcd(k, c);
        //cout << x << ' ' << y << ' ' << g << '\n';
        if (g != 1)
            impossible = true;
        else {
            if (x >= 0) {
                long long n = x / c + 1;
                y += n * k;
            }
            if (y > 1e9)
                impossible = true;
        }
        if (impossible)
            cout << "IMPOSSIBLE" << '\n';
        else
            cout << y << '\n';
    }

    return 0;
}