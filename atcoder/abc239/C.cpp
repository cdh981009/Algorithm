#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 100;

int ans;
int arr[N];
ll n;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    auto q = [&](ll x, ll y) {
        return ((x - x2) * (x - x2) + (y - y2) * (y - y2)) == 5;
    };

    bool pos = q(x1 - 2, y1 - 1) || q(x1 - 1, y1 - 2) ||
               q(x1 + 2, y1 - 1) || q(x1 + 1, y1 - 2) ||
               q(x1 - 2, y1 + 1) || q(x1 - 1, y1 + 2) ||
               q(x1 + 2, y1 + 1) || q(x1 + 1, y1 + 2);

    cout << (pos ? "Yes" : "No") << '\n';
    return 0;
}