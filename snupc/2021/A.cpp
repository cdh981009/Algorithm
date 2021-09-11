#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int(i) = (a); (i) < (b); ++(i))
#define FOR_(i, a, b) for (int(i) = (a); (i) <= (b); ++(i))

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

constexpr int N = 201010;
constexpr int M = 201010;

int n;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll five[10];
    FOR(i, 0, 10) {
        five[i] = 1LL * i * i * i * i * i;
    }
    ll ans = 0;
    cin >> n;
    while (n) {
        int x = n % 10;
        n /= 10;
        ans += five[x];
    }
    cout << ans << '\n';

    return 0;
}