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

    int n; cin >> n;

    int a[2000];
    FOR(i, 0, 1000) a[i] = 1;
    FOR(i, 1000, 2000) a[i] = 1000;
    
    cout << 2000 << '\n';
    FOR(i, 0, 2000) cout << a[i] << ' ';
    cout << '\n';


    return 0;
}