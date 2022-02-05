#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 361;
constexpr int M = 998244353;

ll ans;
ll n;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    while (tc--) {
        ll a, s;
        cin >> a >> s;

        bool b = false;
        ll x = s - (a << 1);
        //cout << x << '\n';
        if (x >= 0) {
            b = !(x & a);
        }

        cout << (b ? "Yes" : "No") << '\n';
    }

    return 0;
}