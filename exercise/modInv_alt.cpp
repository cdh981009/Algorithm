#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define FOR_(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;

    /*
    * inv(1) = 1
    * inv(i) = -(p / i) * inv(p % i)
    */

    /*
    p = p / i * i  + p % i
    -p / i * i = p % i
    inv(i) = inv(p % i) * (-p / i)
    */

    // print (a / b) % c

    vector<int> inv(b + 1, 0);
    inv[1] = 1;
    FOR_(i, 2, b) {
        inv[i] = (inv[c % i] * (-c / i) + c) % c;
    }
    cout << (a * inv[b]) % c << '\n';

    return 0;
}