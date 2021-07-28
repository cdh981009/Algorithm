#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 101010;

int main() {
    freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    
    FOR_(x, -999, 999) {
        FOR_(y, -999, 999) {
            if (a * x + b * y == c && d * x + e * y == f) {
                cout << x << ' ' << y << '\n';
            }
        }
    }

    return 0;
}