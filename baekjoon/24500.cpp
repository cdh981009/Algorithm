#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;

constexpr int N = 1e5;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n; cin >> n;
    int k = 1;
    int i = 0;
    while (true) {
        if (n < (1LL << i)) break;
        i++;
    }
    ll x = (1LL << i) - 1;
    if (n == x) {
        cout << 1 << '\n' << n << '\n';
    } else {
        cout << 2 << '\n' << (x - n) << '\n' << n << '\n';
    }

    return 0;
}