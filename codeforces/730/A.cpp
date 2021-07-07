#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        ll a, b; cin >> a >> b;
        if (a < b)
            swap(a, b);
        ll x = a - b;
        if (x == 0) {
            cout << "0 0\n";
        } else {
            ll y = b % x;
            y = min(abs(y), abs(x - y));
            cout << x << ' ' << y << '\n';
        }
    }
    return 0;
}