#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e9;

int n;
vector<int> primes;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int a, b, c;
        cin >> a >> b >> c;
        int x, y, z;
        z = 1;
        FOR(i, 0, c - 1) {
            z *= 10;
        }
        x = y = z;
        int nx = 1, ny = 1;
        FOR(i, 0, a - 1) {
            nx *= 10;
        }
        FOR(i, 0, b - 1) {
            ny *= 10;
        }
        while (x < nx) {
            x *= 2;
        }
        while (y < ny) {
            y *= 5;
        }
        cout << x << ' ' << y << '\n';
    }
    return 0;
}