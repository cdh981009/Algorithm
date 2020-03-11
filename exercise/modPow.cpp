#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define FOR_(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))

int modPow(int a, int b, int m) {
    if (b == 0) return 1;
    long long h = modPow(a, b/2, m);
    h = (h*h) % m;
    if (b % 2 == 1) h = (h*a) % m;
    return h;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    cout << modPow(a, b, c) << endl;
    return 0;
}