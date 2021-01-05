// 1934: lcm
// https://www.acmicpc.net/problem/1934
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int gcd(int a, int b) {
    if (a > b) swap(a, b);

    while (a != 0) {
        int t = b % a;
        b = a;
        a = t;
    }

    return b;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    while (tc--) {
        int a, b; cin >> a >> b;
        cout << a * b / gcd(a, b) << '\n';
    }

    return 0;
}