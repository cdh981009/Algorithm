#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int(i) = (a); (i) < (b); ++(i))
#define FOR_(i, a, b) for (int(i) = (a); (i) <= (b); ++(i))

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

constexpr int N = 301010;
constexpr int M = 1e9 + 7;

int n;
int arr[N];
int aux[N];

ll modpow(ll a, ll x) {
    ll ret = 1;
    ll base = a;
    while (x) {
        if (x % 2) {
            ret = (ret * base) % M;
        }
        base = (base * base) % M;
        x /= 2;
    }

    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 0, n) {
        cin >> arr[i];
    }

    for (int i = 1; i < (1 << 30); i <<= 1) {
        int cnt = 0;
        FOR(j, 0, n) {
            if (arr[j] & i) {
                cnt++;
            }
        }
        FOR(j, 0, cnt) {
            aux[j] |= i;
        }
    }

    ll ans = aux[0];
    FOR(i, 1, n) {
        ans *= aux[i];
        ans %= M;
    }

    cout << ans << '\n';

    return 0;
}