#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
const int M = 1e9 + 7;

ll n;

int arr[200];

void init() {
    FOR(i, 2, 200) {
        arr[i] = i;
    }

    FOR(i, 2, 200) {
        for(int j = i + i; j < 200; j += i) {
            arr[j] /= arr[i];
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    init();

    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n;
        ll ans = 0;
        ll i = 2;
        while (n) {
            ll x = n / arr[i];
            ans += (i * ((n - x) % M)) % M;
            ans %= M;
            n = x;
            i++;
        }

        cout << ans << '\n';
    }
    return 0;
}