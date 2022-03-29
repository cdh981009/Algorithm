#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define fi first
#define se second
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (ll i = (a); i <= (b); ++i)

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

constexpr int N = 100;
constexpr int M = 998244353;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    FOR(i, 0, 30) {
        FOR(j, 0, 30) {
            if (i == 14) {
                if (j <= 14) {
                    cout << 1 << ' ';
                } else {
                    cout << 225 << ' ';
                }
            } else if (j == 14) {
                if (i < 14) cout << 15 << ' ';
                else cout << 3375 << ' ';
            } else cout << 0 << ' ';
        }
        cout << '\n';
    }


    return 0;
}