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

ll n, m;

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll ans = 0;
    cin >> n >> m;
    if (n < m)
        swap(n, m);

    // n >= m

    ll g = gcd(n, m);
    ans = g * g;
    n /= g;
    m /= g;
    if (n % 2 && m % 2) {
        ans *= 2;
    }

    cout << ans << '\n';

    return 0;
}