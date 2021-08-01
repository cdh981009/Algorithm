#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 201010;
constexpr int M = (1 << 19);

int n;
int ans;
ll arr[N];

int sn;
ll tree[M];

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll rangeQuery(int a, int b) {
    a += sn;
    b += sn;
    ll ret = 0;
    while (a <= b) {
        if (a % 2 == 1) // odd
            ret = gcd(tree[a++], ret);
        if (b % 2 == 0) // even
            ret = gcd(tree[b--], ret);
        a /= 2;
        b /= 2;
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

    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n;
        ll prev;
        cin >> prev;
        FOR(i, 0, n - 1) {
            ll curr;
            cin >> curr;
            ll x = abs(curr - prev);
            arr[i] = x;
            prev = curr;
        }

        ans = 1;
        if (n > 1) {

            for (sn = 1; sn < n; sn <<= 1)
                ;
            FOR(i, 0, sn) {
                tree[i + sn] = i < n - 1 ? arr[i] : 1;
            }
            for (int i = sn - 1; i >= 1; --i) {
                tree[i] = gcd(tree[2 * i], tree[2 * i + 1]);
            }

            FOR(i, 0, n - 1) {
                int x = i;
                int mx = n - 1;
                for(int step = mx; step >= 1; step /= 2) {
                    while (x + step < mx && rangeQuery(i, x + step) > 1) {
                        x += step;
                    }
                }

                if (rangeQuery(i, x) != 1)
                    ans = max(ans, x - i + 2);
            }
        }

        cout << ans << '\n';
    }
    return 0;
}