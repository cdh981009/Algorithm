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

ll xsum[N], ysum[N];
int xcnt[N], ycnt[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vi> a(n + 1, vi(m + 1, 0));

    FOR(i, 0, n) {
        FOR(j, 0, m) {
            cin >> a[i][j];
        }
    }

    ll ans = 0;

    FOR(i, 0, n) {
        FOR(j, 0, m) {
            int x = a[i][j];
            ans -= xsum[x];
            ans += (ll)i * xcnt[x];
            xcnt[x]++;
            xsum[x] += i;
        }
    }

    FOR(j, 0, m) {
        FOR(i, 0, n) {
            int x = a[i][j];
            ans -= ysum[x];
            ans += (ll)j * ycnt[x];
            ycnt[x]++;
            ysum[x] += j;
        }
    }

    cout << ans << '\n';

    return 0;
}