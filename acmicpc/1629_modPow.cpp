#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define FOR_(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))
long long a, b, c;

int modPow(int a, int b) {
    if (b == 0) return 1;
    long long half = modPow(a, b/2);
    half = (half*half) % c;
    if (b % 2 == 1) half = (half*a) % c;
    return half;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b >> c;
    cout << modPow(a, b) << endl;
    return 0;
}