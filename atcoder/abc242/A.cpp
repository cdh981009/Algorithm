#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pii>;

constexpr int N = 101010;
constexpr int M = 100;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c, x;
    cin >> a >> b >> c >> x;
    double ans;
    if (x <= a) {
        ans = 1;
    } else if (x > b) {
        ans = 0;
    } else {
        ans = (double)c / (b - a);
    }
    cout << fixed << setprecision(10) << ans << '\n';

    
    return 0;
}